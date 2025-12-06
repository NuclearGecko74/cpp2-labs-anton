#include <iostream>
#include <memory>

class Node
{
public:
	Node(int val) : 
		m_value(val) 
	{

	}

private:
	int m_value;
	std::unique_ptr<Node> m_left;
	std::unique_ptr<Node> m_right;

	friend class BinaryTree;
	friend std::ostream& operator<<(std::ostream& os, const class BinaryTree& tree);
};

class BinaryTree
{
public:
	BinaryTree() = default;

	void add(int value)
	{
		if (!m_root)
		{
			m_root = std::make_unique<Node>(value);
		}
		else
		{
			insert(m_root.get(), value);
		}
	}

private:
	std::unique_ptr<Node> m_root;

	void insert(Node* node, int value)
	{
		if (value < node->m_value)
		{
			if (!node->m_left)
			{
				node->m_left = std::make_unique<Node>(value);
			}
			else
			{
				insert(node->m_left.get(), value);
			}
		}
		else
		{
			if (!node->m_right)
			{
				node->m_right = std::make_unique<Node>(value);
			}
			else
			{
				insert(node->m_right.get(), value);
			}
		}
	}

	void printInOrder(std::ostream& os, const Node* node) const
	{
		if (!node) return;

		printInOrder(os, node->m_left.get());
		os << node->m_value << '\n';
		printInOrder(os, node->m_right.get());
	}

	friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);
};

std::ostream& operator<<(std::ostream& os, const BinaryTree& tree)
{
	if (tree.m_root)
	{
		tree.printInOrder(os, tree.m_root.get());
	}
	return os;
}

int main()
{
	BinaryTree tree;

	tree.add(3);
	tree.add(5);
	tree.add(2);

	std::cout << tree;

	return 0;
}