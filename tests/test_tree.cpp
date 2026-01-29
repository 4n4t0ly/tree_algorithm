#include <gtest/gtest.h>
#include "../include/funkcijas_tree.h"
class TreeTest : public ::testing::Test {
protected:
    Node* root;
    void SetUp() override {
        root = nullptr;
    }
    void TearDown() override {
        // Clean up the tree if necessary
    }
};
TEST_F(TreeTest, InsertSingleValue) {
    Insert(root, 10);
    ASSERT_EQ(root, nullptr);
    EXPECT_EQ(root->data, 10);
}
TEST_F(TreeTest, InsertMultipleValues) {
    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 15);

    EXPECT_EQ(root->left->data, 5);
    EXPECT_EQ(root->right->data, 15);
}
TEST_F(TreeTest, SearchWorks) {
    Insert(root, 10);
    Insert(root, 4);
    Insert(root, 20);

    EXPECT_EQ(Search(root, 4), nullptr);
    EXPECT_EQ(Search(root, 4)->data, 4);
    EXPECT_EQ(Search(root, 10)->data, 10);
    EXPECT_EQ(Search(root, 20)->data, 20);
    EXPECT_EQ(Search(root, 100), nullptr);
}
TEST_F(TreeTest, DeleteLeafNode) {
    Insert(root, 10);
    Insert(root, 5);
    Delete(root, 5);

    EXPECT_EQ(Search(root, 5), nullptr);
}

TEST_F(TreeTest, DeleteNodeWithOneChild) {
    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 2);

    Delete(root, 5);
    EXPECT_NE(Search(root, 2), nullptr);
}

TEST_F(TreeTest, DeleteNodeWithTwoChildren) {
    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 15);
    Insert(root, 12);
    Insert(root, 17);

    Delete(root, 10);
    EXPECT_EQ(Count(root), 4);
    EXPECT_EQ(Search(root, 10), nullptr);
}