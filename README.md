##CS-235 User Interface Design
###Submitted by Rashmeet Kaur Khanuja
##README

###All files (ofApp.h, ofApp.cpp, main) must be stored in the same directory
###The sound (.mp3) and font (.ttf) must be stored in the sounds and fonts folders in the data folder in bin respectively
###Generate a new project, open in the IDE (steps given for VS 2017 with a C++ 2015 compiler) and copy the header, cpp, and main files to it 
###To compile, press F7, to run, press F5

##Description - 
This is a simple use interface that can be used to create an empty canvas for the user. The user first hears a welcome message (copy welcome.mp3 in the bin folder (located in apps>myapps>yourproject>bin>data under openframeworks directory). There is also a "Menu" button and a welcome message(in "Monotype Corsiva" font) that appear on screen. On moving the mouse on the menu button, the cursor changes, and on clicking it a drop down menu appears. Move the mouse in the menu to keep it open.
The user can drag and drop images in the canvas and perform the following functionality on the images - 
	Translate using the t/T key (cursor changes to hand)
	Scale using the s/S key (cursor changes to double arrow)
	Rotate in 2D using the ctrl key (cursor changes to cross)
	Move in 3D using the alt key
	Reset the 3D movement using the r/R key
	Select a single image by clicking the mouse on it
	Delete an image by selecting it and pressing the delete key
	Draw free-hand by moving the mouse using the d/D key
	Clear the free hand drawing using x/X key
	Toggle between full screen using the tab key
	Save the image using v/V key. The saved image can be found in bin by the name "sanpshot.jpg"
To exit, close the canvas.

##Files added - 
- A folder named "src" that contains the .h, .cpp, and main files
- A sound file "welcome.mp3" to be added in the sounds folder (in data folder in bin)
- A font "xyz.ttf" to be added in the fonts folder (in data folder in bin)
- A readme file
- A screenshot of the resulting canvas in the name  


		