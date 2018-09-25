// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

/*bool List::operator==(const List &rhs){
    if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}

  	return true;
}
*/

bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

double List::size()
{
	double counter = 1;
	if (!empty())
	{
		Node * ptr = first_->next_; // ptr is a pointer object to an object called Node
		while (ptr != NULL)
		{
			ptr = ptr->next_;      // sets ptr equal to second Node
			counter++;

		}
	}
	else
	{
		counter = 0;
	}
	return counter;
}

double List::sum()
{
	double sum;
	if (!empty())
	{
		Node * ptr = first_->next_;  // Is a pointer to first Mem address in the list and copies it to a second list
		sum = first_->entry_;     // sets sum equal to the entry of the first_node
		while (ptr!=NULL)
		{
			sum = sum + ptr->entry_;    // adds the value held currently by sum and adds the next Node's entry
			ptr = ptr->next_;            // sets ptr equal to the next Node
		}
	}
	else
	{
		sum = 0;
	}
	return sum;
}

void List::insertAsLast(double x)		// ptr Is a pointer object called Node
{
	if (!empty())
	{
		Node* ptr = first_;         // ptr is a pointer to the first node

		while (ptr->next_ != NULL)
		{										// iterates through the lists until it hits NULL
			ptr = ptr->next_;
		}
		ptr->next_ = new Node(x, NULL);
	}
	return;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
