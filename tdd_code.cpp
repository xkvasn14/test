//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{

    item_first->pNext = NULL;
    item_first->pPrev = NULL;
    item_first->value = NULL;
}

PriorityQueue::~PriorityQueue()
{/*
    Element_t* item = GetHead();
    Element_t* item_help;
    while (item != NULL)
    {
        item_help = item;
        item = item->pNext;
        delete item_help;
    }*/
}

void PriorityQueue::Insert(int value)
{
    Element_t* item = GetHead();

    if (item->pNext == NULL && item->pPrev == NULL && item->value == NULL)
    {
        item_first->value = value;
    }
    else
    {
         while (item != NULL)
        {
            if (item->pNext == NULL && item->pPrev == NULL)
            {
                if (item->value > value)
                {
                    //Insert to the FRONT
                    Element_t* elmt = new Element_t;
                    elmt->pNext = item;
                    elmt->pPrev = NULL;
                    elmt->value = value;
                    item_first = elmt;
                    item->pPrev = item_first;
                }
                else
                {
                    //Insert to the END
                    Element_t* elmt = new Element_t;
                    elmt->value = value;
                    elmt->pPrev = item;
                    elmt->pNext = NULL;
                    item->pNext = elmt;
                }
                return;
            }
            else if (item->pPrev == NULL && item->pNext != NULL)
            {
                if (item->value > value)
                {
                    //Insert to the FRONT
                    //Item value is bigger then Insert_Item.Value
                    Element_t* elmt = new Element_t;
                    elmt->pNext = item;
                    elmt->pPrev = NULL;
                    elmt->value = value;
                    item_first = elmt;
                    item->pPrev = item_first;
                }
                else
                {/*
                    Element_t* elmt = new Element_t;
                    elmt->pNext = NULL;
                    elmt->pPrev = item;
                    elmt->value = value;
                    item->pNext = elmt;*/
                }
                return;
            }
            else if (item->pPrev != NULL && item->pNext == NULL)
            {
                if (item->value > value)
                {
                    Element_t* elmt = new Element_t;
                    elmt->value = value;
                    elmt->pPrev = item->pPrev;
                    elmt->pNext = item;
                    item->pPrev->pNext = elmt;
                    item->pPrev = item->pPrev->pNext;
                }
                else
                {
                    Element_t* elmt = new Element_t;
                    elmt->value = value;
                    elmt->pPrev = item;
                    elmt->pNext = NULL;
                    item->pNext = elmt;
                }
                return;
            }
            else if (item->pPrev != NULL && item->pNext != NULL)
            {
                //Middle item
                if (item->pPrev->value <= value && item->value >= value)
                {
                    Element_t* elmt = new Element_t;
                    elmt->value = value;
                    elmt->pPrev = item->pPrev;
                    elmt->pNext = item;
                    item->pPrev->pNext = elmt;
                    item->pPrev = elmt;
                }
                return;
            }

            item = item->pNext;
        }
    }
}

bool PriorityQueue::Remove(int value)
{/*
    Element_t* item = Find(value);
    
    if (item != NULL)
    {
        if (item->pNext != NULL && item->pPrev != NULL)
        {
            item->pPrev->pNext = item->pNext;
            item->pNext->pPrev = item->pPrev;
            delete item;
        }
        else if (item->pNext != NULL && item->pPrev == NULL)
        {
            item->pNext->pPrev = NULL;
            item_first = item->pNext;
            delete item;
        }
        else if (item->pNext != NULL && item->pPrev == NULL)
        {
            item->pPrev->pNext = NULL;
            delete item;
        }
        return true;
    }
    else 
    {
        return false;
    }       */
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{ /*
    Element_t* item = GetHead();
    while (item != NULL)
    {
        if (item->value == value)
        {
            return item;
        }
        else{}
        item = item->pNext;
    }*/
    return NULL;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return item_first;
}

/*** Konec souboru tdd_code.cpp ***/
