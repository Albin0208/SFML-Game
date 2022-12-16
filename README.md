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

## Documentation
The documentation is located in the folders ``html`` and ``latex``.


### Requirements to compile
To recompile the documentation install [Doxygen](doxygen.nl/index.html).

#### Compile with UML-diagrams
To recompile the UML diagrams install [Graphviz](https://graphviz.org/).

### Recompile
To recompile the documentation run the command ``doxygen config-file``. Then the ``html`` and ``latex`` folder should be updated.

