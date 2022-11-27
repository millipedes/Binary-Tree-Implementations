/**
 * @file   implementation1.c
 * @brief  This file contains the first implementation of a C program that
 * encodes a binary tree from 1 to (N - 1).
 * @author Matthew C. Lindeman
 * @date   November 10, 2022
 * @bug    None known
 * @todo   Nothing
 */
#include "implementation1.h"

int main(void) {
  bin_tree * bt = init_tree(1);
  for(int i = 2; i < N; i++)
    bt = add_child(bt, i);
  debug_bin_tree(bt, 0);
  free_bin_tree(bt);
  return 0;
}

/**
 * This function initializes a binary tree with no children.
 * @param value - The value that the tree is initialized to.
 * @return   bt - The new tree.
 */
bin_tree * init_tree(int value) {
  bin_tree * bt = calloc(1, sizeof(struct BIN_TREE_T));
  bt->right_child = NULL;
  bt->left_child = NULL;
  bt->value = value;
  return bt;
}

/**
 * This function adds a child to a binary tree.
 * @param  head - The head of the binary tree to be added to.
 * @return head - The tree with the new leaf of value "value"
 */
bin_tree * add_child(bin_tree * bt, int value) {
  if(!bt->left_child)
    bt->left_child = init_tree(value);
  else if(!bt->right_child)
    bt->right_child = init_tree(value);
  else
    next_addative(bt->left_child, bt->right_child, value);
  return bt;
}

/**
 * This function is used to determine the next leaf node.
 * @param
 * @return
 */
void next_addative(bin_tree * bt_left_child, bin_tree * bt_right_child,
    int value) {
  if(!bt_left_child->left_child)
    bt_left_child->left_child = init_tree(value);
  else if(!bt_left_child->right_child)
    bt_left_child->right_child = init_tree(value);
  else if(!bt_right_child->left_child)
    bt_right_child->left_child = init_tree(value);
  else if(!bt_right_child->right_child)
    bt_right_child->right_child = init_tree(value);
  else if(highest_depth(bt_left_child, 0) > highest_depth(bt_right_child, 0))
     return next_addative(bt_right_child->left_child, bt_right_child->right_child,
         value);
  else
     return next_addative(bt_left_child->left_child, bt_left_child->right_child,
         value);
}

/**
 * This function determines the highest quantity of depth that bt has.
 * @param          bt - The binary tree whose depth will be determined.
 * @param  init_depth - The depth that the function requires to return.
 * @return init_depth - The final depth.
 */
int highest_depth(bin_tree * bt, int init_depth) {
  if(bt->left_child && bt->right_child)
    return highest_depth(bt->right_child, init_depth + 1);
  else
    return init_depth;
}

/**
 * This function determins if a level of a binary tree is full (i.e. does this
 * node have two children).
 * @param bt - The binary tree level to check.
 * @return 1 - It is full.
 *         0 0 It is not full.
 */
int is_level_full(bin_tree * bt) {
  if(!bt)
    return 0;
  if(bt->right_child && bt->left_child)
    return 1;
  return 0;
}

/**
 * This function debugs a particular binary tree. It uses tabs to distinguish
 * children.
 * @param    bt - The binary tree to debug
 * @param depth - The depth of the binary tree (i.e. how much to tab its value)
 * @return  N/a
 */
void debug_bin_tree(bin_tree * bt, int depth) {
  if(bt) {
    for(int i = 0; i < depth; i++)
      printf("\t");
    printf("Binary Tree: %d\n", bt->value);
    if(bt->left_child)
      debug_bin_tree(bt->left_child, depth + 1);
    else {
      for(int i = 0; i < depth; i++)
        printf("\t");
      printf("No Left Child\n");
    }
    if(bt->right_child)
      debug_bin_tree(bt->right_child, depth + 1);
    else {
      for(int i = 0; i < depth; i++)
        printf("\t");
      printf("No Right Child\n");
    }
  }
}

/**
 * This function frees a binary tree.
 * @param   bt - The binary tree to free.
 * @return N/a
 */
void free_bin_tree(bin_tree * bt) {
  if(bt) {
    if(bt->left_child)
      free_bin_tree(bt->left_child);
    if(bt->right_child)
      free_bin_tree(bt->right_child);
    free(bt);
  }
}
