# CS-210-CPlusPlus
Repository for CS-210 course where we were taught about C++ and how to integrate languages.
This is Project 1.

# Summarize the project and what problem it was solving.
This project is the first Project of the CS-210 course. We were asked to display a 12-hour and 24-hour clock that started off displaying the current time but then the user could add time by second, minute, and hour. After the project initiation, the clock was static and not moving forward on its own without user input. The clock was supposed to show the correct time and not show an impossible hour or the wrong statement of AM or PM.

# What did you do particularly well?
I implemented a switch loop that ended up working really smooth. I also utilized functions to make the main function small and easily readable. I also cleared the screen between each action to keep the screen free from clutter of previous iterations of the clocks.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could transfer the non main functions to a header file to make the main function in the cpp file even more readable to the user. The code for the actual clock cout statements can be either elongated to more statements to increase the readabilty of that particular function. Or, it could be achieved maybe in a more efficient way. I would also change the color of the text to green to give it a different feel by including the windows.h library. I would also add a little bit more error handing for the menu option choice to ensure nothing crashed the program. If you input a letter into the input, it cause an infinite loop to happen which leads to a program crash.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging aspect of this project was making sure that no matter what the user added to the clock that the clock would display a valid time and adjust when they hit the minute or hour mark. I had to implement if and else if statements to ensure that it ran correctly and would reset back to zero if it would exceed 23 for hours and 59 for minutes.

# What skills from this project will be particularly transferable to other projects or course work?
In creating this project, even though it was not required, I was able to make the clock run and stay in a readable format. Even though this skill was not applicable to this project, it is something that I can carry over to different projects. I also got a lot of practice with functions and how to make main cleaner. 

# How did you make this program maintainable, readable, and adaptable?
I made the program readable by defining functions outside of main to run the actions of adding time to the clocks and displaying the clocks to the user. I also made the program maintable by allowing the option of additional switch options and an easy access to the menu to add another option.
