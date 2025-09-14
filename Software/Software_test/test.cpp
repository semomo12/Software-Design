#include "pch.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"
#include "../Software_lib/InteractionTypes.h"
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <vector>




TEST(InteractWithObjectUseCase, selectObject) {
	//Setup
	Game newGame;
	string objectName = "apple";

	//Call function to test 
	auto resInteractionTypes = newGame.selectGameObject(objectName);
	

	EXPECT_NE(resInteractionTypes[0], nullptr);
	EXPECT_EQ(resInteractionTypes[0]->getName(), "taste");
	EXPECT_EQ(resInteractionTypes[1]->getName(), "touch");
	EXPECT_NE(resInteractionTypes[0]->getName(), "Bob");


	//Teardown happens automatically through destructor.


}

TEST(InteractWithObjectUseCase, selectInteractionType) {
	//Setup
	Game newGame;
	string objectName = "apple";
	auto resInteractionTypes = newGame.selectGameObject(objectName);

	//Call function to test
	auto resSpecificInteractionOptions = newGame.selectInteraction("taste");

	EXPECT_NE(resSpecificInteractionOptions[0], "");
	EXPECT_EQ(resSpecificInteractionOptions[0], "lick");
	EXPECT_EQ(resSpecificInteractionOptions[1], "eat");
	EXPECT_NE(resSpecificInteractionOptions[0], "throw");


	//Teardown happens automatically through destructor.

}

TEST(InteractWithObjectUseCase, selectInteractionOption) {
	//Setup
	Game newGame;
	string objectName = "apple";
	auto resInteractionTypes = newGame.selectGameObject(objectName);
	auto resSpecificInteractionOptions = newGame.selectInteraction("taste");

	//Call function to test
	auto resOptionSelect = newGame.setInteractionOptions("lick");

	EXPECT_NE(resOptionSelect, "Government cuts!! All hail Elon!!");
	EXPECT_NE(resOptionSelect, " ");
	EXPECT_EQ(resOptionSelect, "Option is selected");


	//Teardown happens automatically through destructor.

}
TEST(InteractWithObjectUseCase, startInteraction) {
	//Setup
	Game newGame;
	string objectName = "apple";
	auto resInteractionTypes = newGame.selectGameObject(objectName);
	auto resinteractions = newGame.selectInteraction("taste");
	auto resOptionSelect = newGame.setInteractionOptions("lick");

	//Run function to test
	auto resStartInteraction = newGame.startInteraction();
	
	
	EXPECT_NE(resStartInteraction, "It is Gulf Of America");
	EXPECT_TRUE(resStartInteraction.find("apple") != string::npos && 
				resStartInteraction.find("taste") != string::npos &&
				resStartInteraction.find("lick") != string::npos);
	


	//Teardown happens automatically through destructor.

}