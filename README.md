# CS210-Week-8

# Summarize the project and what problem it was solving.
This is Project 3 from our class. We were provided the TheZoo folder that contained the Debug folder, ZooFileWriter.class, ZooFileWriter.java, and the TheZoo.cpp in /src. TheZoo.cpp contained the function that used the provided Java code to create zoodata.txt and fill it with one or more entries. The objective of the project was to complete TheZoo.cpp and create classes in accordance with the instruction's UML diagram. I created each class that had two functions: print on the screen the object's information, or write that infromation to zoodata.txt. In TheZoo.cpp, I used a global vector of pointers that stored a pointer to each object created by the user. The user then could print, edit, and save the list. 

# What did you do particularly well?
I think what I did best was complete most of the project in one sitting (minus a two hour nap in the middle of the night) and research how to solve each problem I encountered with the project. 

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I am unaware of any improvements I can make on my code without completely restructuring it. After creating all of the classes in accordance with the UML diagram, I was informed by the professor that we could have only made the Animal, Oviparous, and Mammal classes. I think that could have reduced the amount of code I created so I could have avoided an extra six classes, but I think my code is still easy to read and follow along. At the time I am writing this, I am not aware of security concerns with this code. 

# Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?
There were a couple of issues I ran into with this project. I had a logical error when loading data from zoodata.txt - it would add a "1" in front of an entry that followed a different entry that had either an egg or was nursing. I fixed it by initializing the string variable as empty strings during the loop that turned each line from the file into an object in g_list. The next issue I was faced with figuring out how to add different objects to a list. My first attempt was to simply create a vector of Animal objects, but any child class added to the vector would be turn into an Animal object. I had to go back through our course materials and rediscover polymorphism, and I decided it was best to use a vector of pointers that could simply point to an object and use its functions that would override the base class' functions. 

# What skills from this project will be particularly transferable to other projects and/or course work?
I don't think any of this is necessary to complete the other projects from this course as we were able to accomplish those tasks without knowledge we hadn't learned yet. For future projects in my next classes, I think the skills I've learned from this project will be useful and transfer well because it is important to know the basics when using a language. 

# How did you make this program maintainable, readable, and adaptable?
I made the program maintainable and readable with the use of comments and explaining what pieces of my code do where necessary. It is adaptable through to the use of public functions that can be called if an exteral program were to interact with this one. 
