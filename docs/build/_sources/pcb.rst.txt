.. _pcb:

PCB Design
==========


Layer Stack
-----------

After doing much research, we decided to opt for a 4 layer PCB since it only requires a marginal increase in PCB production cost.

Our layer stack is illustrated here:
::
    Top -> Signal Layer
    Middle1 -> GND Plane
    Middle2 -> Pwr Plane (highest voltage takes priority, all other voltages are on a signal layer
    Bottom -> Signal Layer

You may notice that we have isolated power from our signal layers. Not only does this make it much easier to route the PCB (the different components who need power can just receive it from a via to the correct layer), it also helps prevent electromagnetic interference. Since pushing a voltage through a trace creates an electromagetic field around the moving electrons, by isolating the power with the signal, we have less chances of interference where the electromagnetic field created in the traces cause a current in the signal traces and renders our signals unreadable.

