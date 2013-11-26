The STM32F4 Discovery has become quite the popular platform since its release. This code is my attempt at getting the hardware on the board to work with C++ as the development language. The current code is incredibly disorganized and some parts (most parts, actually) are incomplete. This is mostly a test code base. The real framework that I am developing has not been uploaded yet, but wull be soon. However, there is a lot of code in this project that is quite useful. I have kept this code simple for a reason. I want people that stumble across this code to a feel for how the hardware is initialized and works without a bunch of useless junk in the way. I also wanted to demonstrate the use of C++ instead of C.

Features of this code
=============================================================
-  Demonstrate use of ST's Std_Periph_Lib with C++
-  Demonstrate use of some of the peripherals on the STM32F407
-  Demonstrate use of components that are included on the board such as the accelerometer
-  Demonstrate use of timer with C++ code
-  Demonstrate use of interrupts with C++
-  Provide drivers for a couple of popular TFTs
	-  SeeedStudio Touch Shield V1.0 with 8-bit parallel connection
	-  TFT-Proto board from MikroE that uses the ILI9341 driver with 16-bit parallel connection
		-  This one uses FSMC to drive the TFT. It is actually quite fast. You can also see in the code that I am working on implementing the TE line which would allow the developer to not only display static 	
		   images, but also display movies and animations as well

Future Enhancements
=============================================================
There will not be many changes made to this code. Instead, I will eventually upload the entire framework I have created with all of this code (in a completed state) included. That project will be a much better starting point for someone wanting to have a good base to start from. That project also has some graphics libs included that are not included here to help with drawing and managing screens.

Again, I am sorry for the state of this code. I really just needed a place to put it so that I didn't lose it by accident, which happens occassionally.