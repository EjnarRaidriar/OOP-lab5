# Refactoring Process

1. ## Program Stucture

    - I added structure to program files and decoupled declaration of a class and it's implementation

    >lib  
    >lab5  
 ┣ lib  
 ┃ ┣ resources  
 ┃ ┃ ┣ fish  
 ┃ ┃ ┃ ┣ Fish.cpp  
 ┃ ┃ ┃ ┗ Fish.hpp  
 ┃ ┃ ┣ mineral  
 ┃ ┃ ┃ ┣ Mineral.cpp  
 ┃ ┃ ┃ ┗ Mineral.hpp  
 ┃ ┃ ┣ wood  
 ┃ ┃ ┃ ┣ Wood.cpp  
 ┃ ┃ ┃ ┗ Wood.hpp  
 ┃ ┃ ┣ Resource.cpp  
 ┃ ┃ ┗ Resource.hpp  
 ┃ ┣ tools  
 ┃ ┃ ┣ axe  
 ┃ ┃ ┃ ┣ Axe.cpp  
 ┃ ┃ ┃ ┗ Axe.hpp  
 ┃ ┃ ┣ pickaxe  
 ┃ ┃ ┃ ┣ Pickaxe.cpp  
 ┃ ┃ ┃ ┗ Pickaxe.hpp  
 ┃ ┃ ┣ rod  
 ┃ ┃ ┃ ┣ Rod.cpp  
 ┃ ┃ ┃ ┗ Rod.hpp  
 ┃ ┃ ┣ Tool.cpp  
 ┃ ┃ ┗ Tool.hpp  
 ┃ ┣ workers  
 ┃ ┃ ┣ fisher  
 ┃ ┃ ┃ ┣ Fisher.cpp  
 ┃ ┃ ┃ ┗ Fisher.hpp  
 ┃ ┃ ┣ forester  
 ┃ ┃ ┃ ┣ Forester.cpp  
 ┃ ┃ ┃ ┗ Forester.hpp  
 ┃ ┃ ┣ miner  
 ┃ ┃ ┃ ┣ Miner.cpp  
 ┃ ┃ ┃ ┗ Miner.hpp  
 ┃ ┃ ┣ Worker.cpp  
 ┃ ┃ ┗ Worker.hpp  
 ┃ ┣ Biom.h  
 ┃ ┣ City.h  
 ┃ ┗ colors.h  
 ┣ src  
 ┃ ┗ Simulation.cpp  
 ┣ Makefile  
 ┗ Readme.md  
    >

2. ## Resource classes

    - Added a function to return class name

    ![f](.photos/class%20name.png)  
    this function will be implemented in each subclass

    - Class *Mineral* changed its name to *Iron*

3. ## Tool classes

    - Added a function to return class name

    ![f](.photos/class%20name.png)

    - Deleted function

    ![a](.photos/Sharpen%20deleted.png)

4. ## Worker classes

    - for the funciton *collectResources()* I added different implementation for each subclass of Worker depending on their specialization and the tool used

    ![fdsa](.photos/Screenshot%202022-12-02%20154535.png)

    - Created a new interface for iron tool users

    ![a](.photos/IronToolUser%20interface.png)

    - moved output data from subclasses to parent class in order to avoid repetition

    ![a](.photos/worker%20data%20output.png)

    - deleted tools vector from each subclass and moved to parent class

    ![a](.photos/tools%20vector.png)

    ![a](.photos/worker%20data.png)

    now each worker can store different tools and resources, but the *collectResources()* function will determine their efficiency with each tool and resource
