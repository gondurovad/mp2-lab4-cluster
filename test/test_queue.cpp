#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> p(4));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue<int> p(-4));
}

TEST(Queue, cant_add_in_full_queue)
{
	ASSERT_ANY_THROW(Queue<int> p(MaxSizeQueue + 1));
}

TEST(Queue, can_push_val)
{
	Queue<int> p(4);
	ASSERT_NO_THROW(p.Push(2));
}

TEST(Queue, can_pop_val)
{
	Queue<int> p(2);
	p.Push(1);
	ASSERT_NO_THROW(p.Pop());
}

TEST(Queue, can_check_queue_is_empty)
{
	Queue<int> p(4);
	p.Push(1);
	EXPECT_EQ(p.IsEmpty(), 0);
}

TEST(Queue, can_check_queue_is_full)
{
	Queue<int> p(2);
	p.Push(1);
	p.Push(2);
	EXPECT_EQ(p.IsFull(), 1);
}

TEST(Queue, cant_pop_val_from_empty_queue)
{
	Queue<int> p(2);
	p.Push(1);
	p.Pop();
	ASSERT_ANY_THROW(p.Pop());
}

TEST(Queue, cant_push_val_in_full_queue)
{
	Queue<int> p(2);
	p.Push(1);
	p.Push(2);
	ASSERT_ANY_THROW(p.Push(3));
}

