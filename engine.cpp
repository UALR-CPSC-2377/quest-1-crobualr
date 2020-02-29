
#include "engine.h"

// stdlib
#include <fstream>
#include <iostream>
#include <random>
// local
#include "Object.h"
#include "GUI.h"
using namespace std;
int
loadBlockData (
    const std::string& p_gameFile,
    Object p_objects[],
    const GUI& p_gui
) {
    /*
        -- loadBlockData   --
        Parameters:
            p_gameFile : A string representing the location of the game data file
            p_objects  : An array of default-constructed objects, each element
                         needs to be updated to with the correct information from
                         the data file
            p_gui      : A reference to the GUI Object if you need it

        Return: the number of objects read from the data file

        loadBlockData will read the p_gameFile and update the objects in
        p_objects with the appropriate data.
    */
    int objectsRead = 0;
    int objectData = 0;
    int index = 1;
    ifstream fin;
    fin.open(p_gameFile);
    while (!fin.eof()) {
        fin >> objectData;
        p_objects[index].type = (Type)objectData;
        cout << objectData << endl;;
        index++;
        objectsRead++;
    }
    fin.close();
    int i = 1;
    for (int row = 0; row < 14; row++) {
        for (int col = 0; col < 21; col++) {
            Dimensions dimension{ p_gui.getObjectDimensions(p_objects[i]) };
            p_objects[i].position.x = col * dimension.width;
            p_objects[i].position.y = row * dimension.height;
            p_objects[i].dimensions.width = dimension.width;
            p_objects[i].dimensions.height = dimension.height;
            i++;
        }
    }
    cout << "objects read: " << objectsRead;
    return objectsRead; // placeholder
}

void
randomPlayerData (
    const int p_numObjects,
    Object p_objects[],
    const GUI & p_gui
) {
    /*
        -- randomPlayerData   --
        Parameters:
            p_numObjects : The total number of objects in p_objects
            p_objects    : An array of almost all fully-constructed objects
            p_gui      : A reference to the GUI Object if you need it

        This function needs to modify the player object and assign them random values.
        Player
            xPosition needs to be random
            spriteID needs to be random
            yPosition needs to be physically correct
                The player cannot be in the air for instance
                The player cannot be underground
    */
    random_device rdev; //seed
    default_random_engine e(rdev()); //engine

    uniform_int_distribution<int> s(0, p_gui.getNumPlayerSprites() - 1);
    int randomValueSprite = s(e); //distribution(engine)
    p_objects[0].spriteID = randomValueSprite;

    int screenWidth = p_gui.screenDimensions.width;
    uniform_int_distribution<int> d(0, screenWidth - p_gui.getObjectDimensions(p_objects[0].dimensions.width));
    int randomValue = d(e); //distribution(engine)
    p_objects[p_numObjects - 1].position.x = randomValue;
    //p_objects[p_numObjects - 1].position.y = 
}

int
getMaxYOfBlock (
    const Object& player,
    const Object objects[],
    int numObjects
) {
    /*
        -- getMaxYOfBlock --
        Parameters
            player  - A read-only reference to the player object
            objects - A list of read-only objects
            numObjects - The number of objects

        Return: The height that the player needs to be at to be physically accurate
    */

    return 0; // placeholder
}
