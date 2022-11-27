/**
 * @file   implementation1.c
 * @brief  This file contains the function definitions for implementation1.c
 * @author Matthew C. Lindeman
 * @date   November 10, 2022
 * @bug    None known
 * @todo   Nothing
 */
#ifndef IMPO
#define IMPO

#include <stdio.h>
#include <stdlib.h>

#define N 25

typedef struct BIN_TREE_T {
  int value;
  struct BIN_TREE_T * right_child;
  struct BIN_TREE_T * left_child;
} bin_tree;

bin_tree * init_tree(int value);
bin_tree * add_child(bin_tree * bt, int value);
void next_addative(bin_tree * bt_left_child, bin_tree * bt_right_child,
    int value);
int highest_depth(bin_tree * bt, int init_depth);
int is_level_full(bin_tree * bt);
void debug_bin_tree(bin_tree * bt, int depth);
void free_bin_tree(bin_tree * bt);

#endif
