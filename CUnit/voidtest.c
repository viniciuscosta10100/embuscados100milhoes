#include <stdio.h>
#include "stack.h"
#include "CUnit/Basic.h"

void test_stack(){
	Pilha *stack = initStack();
	push (stack, 3);
	CU_ASSERT_EQUAL (peek(stack), 3);
	push (stack, 6);
	CU_ASSERT_EQUAL (peek(stack), 6);
	push (stack, 9);
	CU_ASSERT_EQUAL (peek(stack), 9);
	push (stack, 11);
	CU_ASSERT_EQUAL (peek(stack), 11);
	pop (stack);
	CU_ASSERT_EQUAL (peek(stack), 9);
	pop (stack);
	CU_ASSERT_EQUAL (peek(stack), 6);
	pop (stack);
	CU_ASSERT_EQUAL (peek(stack), 3);
	pop (stack);
	CU_ASSERT_EQUAL (peek(stack), -1);
}

int main(){
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	CU_basic_set_mode(CU_BRM_VERBOSE);

	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("sum_test_stack", 0, 0);

	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(pSuite, "test_stack", test_stack)) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	CU_basic_run_tests();
	return CU_get_error();
}
