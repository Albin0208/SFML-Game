## Play the game
### Get the project

Run the command:

``git clone https://gitlab.liu.se/albda746/tdp005.git``

Or download the project from [here](https://gitlab.liu.se/albda746/tdp005/-/archive/master/tdp005-master.zip).


### Compile
1. To compile the game, download [SFML](https://www.sfml-dev.org/).
2. Run the command ``cmake .`` in the root folder of the project.
3. Run the command ``make``

The program is now compiled in a file called ``TDP005``.

### Run the game
To run the game run the command ``./TDP005``

## Controls

#### Movement
Move the player by using ``wasd`` or the ``arrow keys``.

#### Shoot projectiles
Aim the cursor in the direction where you want to shoot then press ``Mouse 1`` to fire.

## Documentation
The documentation is located in the folders ``html`` and ``latex``.
If they don't exist you have to generate the documentation with the commant ``doxygen config-file``. 


### Requirements to compile
To recompile the documentation install [Doxygen](doxygen.nl/index.html).

#### Compile with UML-diagrams
To recompile the UML diagrams install [Graphviz](https://graphviz.org/).

### Recompile
To recompile the documentation run the command ``doxygen config-file``. Then the ``html`` and ``latex`` folder should be updated.

