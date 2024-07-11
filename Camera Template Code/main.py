import sensor
import time
import math
from machine import PWM
from machine import Pin

bufferVal = 40

# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below thresholds track in general red/green things. You may wish to tune them...
thresholds = [
   (72, 90, -4, 36, 24, 48),
   (14, 33, -11, 10, -47, -12)

]  # generic_blue_thresholds
# You may pass up to 16 thresholds above. However, it's not really possible to segment any
# scene with 16 thresholds before color thresholds start to overlap heavily.

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time=2000)
sensor.set_auto_gain(False)  # must be turned off for color tracking
sensor.set_auto_whitebal(False)  # must be turned off for color tracking
clock = time.clock()
p = Pin("P3", Pin.OUT)


pwm = PWM(p, 1000)

def maptrans(num, inMin, inMax, outMin, outMax):
  return outMin + (float(num - inMin) / float(inMax - inMin) * (outMax
                  - outMin))



# Only blobs that with more pixels than "pixel_threshold" and more area than "area_threshold" are
# returned by "find_blobs" below. Change "pixels_threshold" and "area_threshold" if you change the
# camera resolution. Don't set "merge=True" because that will merge blobs which we don't want here.

while True:
    clock.tick()
    img = sensor.snapshot()
    blobs = img.find_blobs(thresholds, pixels_threshold=200, area_threshold=200)
    if blobs:
        largest = blobs[0]
        for blobsss in blobs:
            if blobsss.area() > largest.area():
                largest = blobsss

        blob = largest
        if blob.cy() > (240/2)+20:
            # These values depend on the blob not being circular - otherwise they will be shaky.
            if blob.elongation() > 0.5:
                img.draw_edges(blob.min_corners(), color=(255, 0, 0))
                img.draw_line(blob.major_axis_line(), color=(0, 255, 0))
                img.draw_line(blob.minor_axis_line(), color=(0, 0, 255))
            # These values are stable all the time.
            img.draw_rectangle(blob.rect())
            img.draw_cross(blob.cx(), blob.cy())

            if blob.cx() < (320/2)-bufferVal:
                print("Left: " + str(int(maptrans(blob.cx(), 0, 320, 0, 250))))
                print(int(maptrans(blob.cx(), 0, 320, 0, 250)))
                pwm.duty_ns(int(maptrans(blob.cx(), 0, 320, 0, 250))*1000)
            elif blob.cx() > (320/2)+bufferVal:
                print("Right: " + str(int(maptrans(blob.cx(), 0, 320, 0, 250))))
                pwm.duty_ns(int(maptrans(blob.cx(), 0, 320, 0, 250))*1000)
            else:
                print("Center: " + str(int(maptrans(blob.cx(), 0, 320, 0, 250))))
                pwm.duty_ns(int(maptrans(blob.cx(), 0, 320, 0, 250))*1000)

            if blob.area() > 8000:

                print("Near")

            # Note - the blob rotation is unique to 0-180 only.
            img.draw_keypoints(
                [(blob.cx(), blob.cy(), int(math.degrees(blob.rotation())))], size=20
            )
        #print(clock.fps())

    else:
        pwm.duty_ns(500000)
    print(pwm.duty_ns())
