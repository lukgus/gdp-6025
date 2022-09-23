#include <pugixml/pugixml.hpp>
#include <iostream>

#include <vector>
using namespace std;
namespace IteratorExample
{
	struct Node {
		Node()
			: NextNode(nullptr)
			, PrevNode(nullptr)
			, value(0)
		{ }

		Node* NextNode;
		Node* PrevNode;
		int value;
	};

	// begin		
	// compare		
	// increment	
	// end			
	// dereference	

	class LinkedList {
	public:
		LinkedList() {
			m_Begin = new Node();
			m_End = new Node();

			m_Begin->NextNode = m_End;
			m_End->PrevNode = m_Begin;
		}

		void push_back(int value) {
			Node* n = new Node();
			n->PrevNode = m_End->PrevNode;
			n->NextNode = m_End;
			n->value = value;

			m_End->PrevNode->NextNode = n;
			m_End->PrevNode = n;
		}

		class Iterator {
		public:
			Iterator(Node* n) {
				m_Node = n;
			}

			void operator++() {
				m_Node = m_Node->NextNode;
			}

			void operator=(const Iterator& it) {
				m_Node = it.m_Node;
			}

			bool operator==(const Iterator& it) {
				return m_Node == it.m_Node;
			}

			bool operator!=(const Iterator& it) {
				return m_Node != it.m_Node;
			}

		private:
			Node* m_Node;
		};

		Iterator begin() {
			return Iterator(m_Begin->NextNode);
		}

		Iterator end() {
			return Iterator(m_End);
		}

	private:
		Node* m_Begin;		// does not carry any cargo, not data
		Node* m_End;		// Tail of the train, contains no cargo
	};

	typedef vector<int>::iterator int_vec_iterator;

	void IteratorExample() {
		vector<int> vec;
		vector<int>::iterator vecIt = vec.begin();

		LinkedList list;
		LinkedList::Iterator nodeIt = list.begin();
		for (LinkedList::Iterator nodeIt = list.begin();
			nodeIt != list.end();
			++nodeIt) {

		}
	}
}

int main(int argc, char** argv) {
	// Create a document object
	pugi::xml_document bookstore;

	// Load a xml file into the object
	pugi::xml_parse_result result = bookstore.load_file("bookstore.xml");
	if (!result) {
		printf("Failed to load 'bookstore.xml'\n");
		return -1;
	}
	printf("Successfully loaded 'bookstore.xml'\n");

	// Use that xml object to read data from
	pugi::xml_object_range<pugi::xml_node_iterator> books = bookstore.child("bookstore").children();
	if (books.empty()) {
		printf("There are no books in the bookstore!\n");
		return 0;
	}

	// Parse through the tree of the XML Data using iterators
	// <bookstore>
	pugi::xml_node_iterator bookIt;
	for (bookIt = books.begin(); 
		bookIt != books.end(); 
		bookIt++)
	{
		pugi::xml_node bookNode = *bookIt;
		pugi::xml_attribute category = bookNode.attribute("category");
		printf("Category: %s\n", category.value());

		// <book>
		pugi::xml_node_iterator bookInfoIt;
		for (bookInfoIt = bookNode.children().begin();
			bookInfoIt != bookNode.children().end();
			bookInfoIt++)
		{
			pugi::xml_node bookInfoNode = *bookInfoIt;
			printf(" %s: %s\n", bookInfoNode.name(), bookInfoNode.child_value());

			// attributes of book children
			for (pugi::xml_attribute_iterator attIt = bookInfoNode.attributes_begin();
				attIt != bookInfoNode.attributes_end();
				attIt++)
			{
				pugi::xml_attribute attribute = *attIt;
				printf("   %s: %s\n", attribute.name(), attribute.value());
			}
		}
	}

	return 0;
}
