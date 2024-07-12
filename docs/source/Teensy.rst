.. _Teensy:

Teensy
======

motorControlV3
--------------

.. cpp:class:: motorControlV3::Motor

    Motor class, handles all of our motor controls. Accessed by the bottom file.

    .. cpp:function:: void motorControlV3::Motor::initMotors(void)

        Initializes the pins. Pins are hard-locked to 3, 1, 5, 37 for the direction pins and 2, 0, 4, 36 for the pwm pins for the `Pololu G2 24v21 Motor Drivers <https://www.pololu.com/product/2995>`_.

    .. cpp:function:: void motorControlV3::Motor::setMotor(int motor, int dir, int pwm)

        Sets one motor direction and speed.

            - int motor: Motor number that should have its speed and direction set. Not needed when calling `:cpp:class:motorControlV3::Motor::moveRobot`.
            - int dir: direction value (0 or 1)
            - int pwm: pwm value to send to power motors at a certain speed (0-255)

    .. cpp:function:: int motorControlV3::Motor::movementSineFunction(int motor, float ballAngleDegrees, boolean isCounter, int amplitude)

        Uses a sine function associated with each motor assembly to move in a direction from the according point in the sine wave given the ball direction.

        Returns an integer value for the pwm motor value for the motor given in the parameters.

            - int motor: Motor number that we are calculating the appropriate value for.
            - float ballAngleDegrees: Degrees of ball angle given in the IR code as a floating point number.
            - boolean isCounter: True if motor is backwards, else false.
            - int amplitude: Amplitude of the sine wave, also the distance to the ball that we want to stay away when navigating to the perpendicular.

    .. cpp:function:: void motorControlV3::Motor::moveRobot(int speed1, int speed2, int speed3, int speed4)

        Move robot with the speeds given for motors 1-4.

            - int speed1: Speed of motor 1. (Can be -255 to 255)
            - int speed2: Speed of motor 2. (Can be -255 to 255)
            - int speed3: Speed of motor 3. (Can be -255 to 255)
            - int speed4: Speed of motor 4. (Can be -255 to 255)

colorSensorV2
-------------
.. cpp:class:: colorSensorV2::ColorSensor

    ColorSensor class, handles all the input from our color sensors. There are 16 color sensors: 16 LEDs and 16 940nm photodiodes. All photodiodes output an analog value which is read by the ADC of our bottom Teensy.

    .. cpp:function:: int colorSensorV2::ColorSensor::readSensor(int sensor)

        Read the sensor specified and returns an arbitrary int value for the detected amount of red light that is used in comparisons with other values.

            - int sensor: Takes the sensor pin number. Refer to schematics for sensor numbers.

    .. cpp:function:: void colorSensorV2::ColorSensor::colourSensorInit(void)

        Initializes color sensors. Takes no parameters.


Compass
-------

.. cpp:class:: Compass::Compass

    Compass class, uses Adafruit.h as a dependency for access to the BNO085 compass output.

    .. cpp:function:: void Compass::Compass::init(void)

        Initialize the compass by beginning Serial connection to the BNO085.

            Does not print anything and just opens the connection.

    .. cpp:function:: void Compass::Compass::initPrint(void)

        Initialize the compass by beginning Serial connection to the BNO085.

            Prints a confirmation message and opens the connection.

    .. cpp:function:: void Compass::Compass::resetCheck(void)

            Checks if BNO085 has been reset. Sets the desired output again.

                Does not print a confirmation message and just performs the check and set.


    .. cpp:function:: void Compass::Compass::resetCheckPrint(void)

            Checks if BNO085 has been reset. Sets the desired output again.

                Prints a confirmation message and performs the check and set.

    .. cpp:function:: float Compass::Compass::getBotAngle(void)

            Gets the current bot angle based off the BNO085

                Returns a floating point value of the angle scale value from -1.00 to 1.00 where 0 is the direction it initializes in.