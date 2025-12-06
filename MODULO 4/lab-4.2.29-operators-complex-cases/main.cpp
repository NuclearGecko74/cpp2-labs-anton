#include <iostream>
#include <vector>
#include <memory>

struct Node
{
	int m_value;
	std::unique_ptr<Node> m_left;
	std::unique_ptr<Node> m_right;

	Node(int val) : m_value(val) {}
};

class BinaryTree
{
public:
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

protected:
	std::unique_ptr<Node> m_root;

	void insert(Node* node, int value)
	{
		if (value < node->m_value)
		{
			if (!node->m_left)
				node->m_left = std::make_unique<Node>(value);
			else
				insert(node->m_left.get(), value);
		}
		else
		{
			if (!node->m_right)
				node->m_right = std::make_unique<Node>(value);
			else
				insert(node->m_right.get(), value);
		}
	}
};

class InOrder : public BinaryTree
{
public:
	int operator[](int index) const
	{
		std::vector<int> nodes;
		collect(m_root.get(), nodes);
		return nodes[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const InOrder& tree);

private:
	void collect(Node* node, std::vector<int>& nodes) const
	{
		if (node)
		{
			collect(node->m_left.get(), nodes);
			nodes.push_back(node->m_value);
			collect(node->m_right.get(), nodes);
		}
	}
};

std::ostream& operator<<(std::ostream& os, const InOrder& tree)
{
	std::vector<int> nodes;
	tree.collect(tree.m_root.get(), nodes);
	for (const auto& val : nodes)
	{
		os << val << " ";
	}
	return os;
}

class PostOrder : public BinaryTree
{
public:
	int operator[](int index) const
	{
		std::vector<int> nodes;
		collect(m_root.get(), nodes);
		return nodes[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const PostOrder& tree);

private:
	void collect(Node* node, std::vector<int>& nodes) const
	{
		if (node)
		{
			collect(node->m_left.get(), nodes);
			collect(node->m_right.get(), nodes);
			nodes.push_back(node->m_value);
		}
	}
};

std::ostream& operator<<(std::ostream& os, const PostOrder& tree)
{
	std::vector<int> nodes;
	tree.collect(tree.m_root.get(), nodes);
	for (const auto& val : nodes)
	{
		os << val << " ";
	}
	return os;
}

class PreOrder : public BinaryTree
{
public:
	int operator[](int index) const
	{
		std::vector<int> nodes;
		collect(m_root.get(), nodes);
		return nodes[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const PreOrder& tree);

private:
	void collect(Node* node, std::vector<int>& nodes) const
	{
		if (node)
		{
			nodes.push_back(node->m_value);
			collect(node->m_left.get(), nodes);
			collect(node->m_right.get(), nodes);
		}
	}
};

std::ostream& operator<<(std::ostream& os, const PreOrder& tree)
{
	std::vector<int> nodes;
	tree.collect(tree.m_root.get(), nodes);
	for (const auto& val : nodes)
	{
		os << val << " ";
	}
	return os;
}

int main()
{
	InOrder inOrderTree;
	inOrderTree.add(3);
	inOrderTree.add(5);
	inOrderTree.add(6);
	inOrderTree.add(1);

	PostOrder postOrderTree;
	postOrderTree.add(3);
	postOrderTree.add(5);
	postOrderTree.add(6);
	postOrderTree.add(1);

	PreOrder preOrderTree;
	preOrderTree.add(3);
	preOrderTree.add(5);
	preOrderTree.add(6);
	preOrderTree.add(1);

	std::cout << "Inorder: " << inOrderTree << std::endl;
	std::cout << "Postorder: " << postOrderTree << std::endl;
	std::cout << "Preorder: " << preOrderTree << std::endl;

	return 0;
}