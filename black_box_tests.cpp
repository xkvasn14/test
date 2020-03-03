//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"


class EmptyTree : public BinaryTree, public testing::Test
{
    protected:
        BinaryTree Tree;
};

class NonEmptyTree : public BinaryTree, public testing::Test
{
    protected:   
        BinaryTree Tree;
        std::vector<int> vectr = { 1,7,3,4,10 };
        std::vector<std::pair<bool, Node_t*>> outNewNodes;
};
    

TEST_F(EmptyTree, InsertNode)
{
    //insert of node_1
    std::pair<bool, Node_t*> node_1;
    node_1 = InsertNode(1);
    EXPECT_TRUE(node_1.first);
    EXPECT_NE(node_1.second, nullptr);

    //insert of node_2
    std::pair<bool, Node_t*> node_2;
    node_2 = InsertNode(2);
    EXPECT_NE(node_1.second, node_2.second);
    EXPECT_TRUE(node_2.first);
    
    EXPECT_EQ(node_2.second->pParent->key, 1);
    EXPECT_EQ(node_1.second->pRight->key, 2);

    //insert of node 3
    std::pair<bool, Node_t*> node_3;
    node_3 = InsertNode(3);
    EXPECT_NE(node_1.second, node_3.second);
    EXPECT_NE(node_2.second, node_3.second);
    EXPECT_TRUE(node_3.first);

    EXPECT_EQ(node_3.second->pParent->key, node_2.second->key);
    EXPECT_EQ(node_3.second->pParent->pLeft->key, node_1.second->key);

}

TEST_F(EmptyTree, DeleteNode)
{
    EXPECT_FALSE(DeleteNode(1));
    std::pair<bool, Node_t*> node_1;
    node_1 = InsertNode(1);
    EXPECT_TRUE(DeleteNode(1));
    EXPECT_FALSE(FindNode(1));
}

TEST_F(EmptyTree, FindNode)
{
    EXPECT_EQ(FindNode(1),nullptr);
    std::pair<bool, Node_t*> node_1;
    node_1 = InsertNode(1);
    EXPECT_NE(FindNode(1), nullptr);
    EXPECT_EQ(FindNode(1), node_1.second);
}

/////////////////////////////////////////////////////////////////////

TEST_F(NonEmptyTree, InsertNode)
{
    Tree.InsertNodes(vectr, outNewNodes);
    //TESTING NEW NODE IN TREE
    std::pair<bool, Node_t*> node_1 = Tree.InsertNode(5);
    EXPECT_TRUE(node_1.first);

    //TESTING NODE IN TREE
    std::pair<bool, Node_t*> node_2 = Tree.InsertNode(4);
    EXPECT_FALSE(node_2.first);

    //TESTING CONNECTION BETWEEN 
    std::pair<bool, Node_t*> node_3 = Tree.InsertNode(6);
    EXPECT_TRUE(node_3.first);
    EXPECT_EQ(node_3.second->pParent->key,node_1.second->key);
}

TEST_F(NonEmptyTree, DeleteNode)
{
    Tree.InsertNodes(vectr, outNewNodes);
    //INSERTING AND DELETING NODE
    std::pair<bool, Node_t*> node_1 = Tree.InsertNode(5);
    //EXPECT_TRUE(Tree.DeleteNode(5));

    for (int i = 0; i < outNewNodes.size(); i++)
    {
        //EXPECT_DOUBLE_EQ(i, 9);
        //EXPECT_DOUBLE_EQ(outNewNodes[i].second->key, 100);
        EXPECT_TRUE(Tree.DeleteNode(outNewNodes[i].second->key));
    }
}

TEST_F(NonEmptyTree, FindNode)
{
    Tree.InsertNodes(vectr, outNewNodes);
    //FINDING BY ARR POSITION
    EXPECT_NE(Tree.FindNode(outNewNodes[0].second->key),nullptr);
    EXPECT_NE(Tree.FindNode(outNewNodes[1].second->key),nullptr);
    EXPECT_NE(Tree.FindNode(outNewNodes[2].second->key),nullptr);
    EXPECT_NE(Tree.FindNode(outNewNodes[3].second->key),nullptr);
    EXPECT_NE(Tree.FindNode(outNewNodes[4].second->key),nullptr);
    EXPECT_DEATH_IF_SUPPORTED(Tree.FindNode(outNewNodes[5].second->key),"");

    //FINDING BY NUMBER
    EXPECT_NE(Tree.FindNode(1),nullptr);
    EXPECT_NE(Tree.FindNode(3),nullptr);
    EXPECT_NE(Tree.FindNode(4),nullptr);
    EXPECT_NE(Tree.FindNode(7),nullptr);
    EXPECT_NE(Tree.FindNode(10),nullptr);
    EXPECT_EQ(Tree.FindNode(2),nullptr);
}

//////////////////////////////////////////////////////////////////////

TEST_F(NonEmptyTree, Axiom1)
{

}
//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

/*** Konec souboru black_box_tests.cpp ***/
