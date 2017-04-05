#include <assert.h>
#include"assert_func.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    void test (struct university * univers[]){
      assert( file_process (" ", univers) == 1);
      assert( file_process ("read.txt",univers ) == 0);
      assert( file_process ("*read.exe*", univers) == 1);
    }

    void testfx (struct university * univers[]){
      assert( file_write (univers) == 0);
    }

    void test_delete_struct (struct university * univers[]){
      assert( delete_from_struct (univers, 1) == NULL);
      assert( delete_from_struct (univers, 25) == NULL);
      assert( delete_from_struct (univers, -5) != NULL);
    }
