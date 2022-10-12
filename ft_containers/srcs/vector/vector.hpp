#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <string>
#include <iostream>
#include "vector_iterator.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/distance.hpp"
#include "../../utils/reverse_iterator.hpp"
#include "../../utils/swap.hpp"


#define RED_COLOR   "\033[31m"
#define RESET       "\033[0m"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                               value_type;
            typedef Allocator                                       allocator_type;
            typedef std::size_t                                     size_type;
            typedef std::ptrdiff_t                                  difference_type;
            typedef value_type&                                     reference;
            typedef const value_type&                               const_reference;
            typedef typename Allocator::pointer                     pointer;
            typedef typename Allocator::const_pointer               const_pointer;
            typedef ft::vectorIterator<value_type>                  iterator;
            typedef ft::vectorIterator<const value_type>            const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _end_capacity;

        public:

            /*----------------------------------*/
            /*           basic function         */
            /*----------------------------------*/

            /*--------constructor*/
            explicit vector (const Allocator& alloc = std::allocator<T>());

            explicit vector (size_type count, const T &value = T(), const Allocator &alloc = Allocator());

            /*this constructor is declare here because of "enable_if" to make shure inputIt is an itterator*/
            template <class InputIt>
            vector (InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<InputIt::input_iter, InputIt>::type = NULL)
            : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL) {this->insert(_end, first, last);};

            vector(const vector &cpy);

            /*----------destructor*/
            ~vector(void);

            /*----------assignement operator*/
            vector  &operator=(const vector &cpy);

            /*----------assign*/
            void assign(size_type count, const T &value);

            /*this assign is declare here because of "enable_if" to make shure inputIt is an itterator*/
            template<class InputIt>
            void assign(InputIt first, InputIt last, typename ft::enable_if<InputIt::input_iter, InputIt>::type = NULL)
            {
                this->clear();
                this->insert(_end, first, last);
            };

            /*-----------get_alocator*/
            allocator_type get_allocator() const;


            /*----------------------------------*/
            /*           access elements        */
            /*----------------------------------*/

            /*-----------at*/
            reference at(size_type pos);
            const_reference at(size_type pos) const;

            /*-----------operator[]*/
            reference operator[]( size_type pos );
            const_reference operator[]( size_type pos ) const;

            /*-----------front*/
            reference front();
            const_reference front() const;

            /*-----------back*/
            reference back();
            const_reference back() const;

            /*-----------data*/
            value_type* data();
            const T* data() const;


            /*----------------------------------*/
            /*           iterators              */
            /*----------------------------------*/

            /*--------begin*/
            iterator begin();
            const_iterator begin() const;

            /*--------end*/
            iterator end();
            const_iterator end() const;

            /*--------rbegin*/
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;

            /*--------rend*/
            reverse_iterator rend();
            const_reverse_iterator rend() const;


            /*----------------------------------*/
            /*           capacity               */
            /*----------------------------------*/

            /*--------empty*/
            bool empty() const;

            /*--------size*/
            size_type size() const;

            /*---------max_size*/
            size_type max_size() const;

            /*---------reserve*/
            void reserve(size_type new_cap);

            /*---------capacity*/
            size_type capacity() const;

            
            /*----------------------------------*/
            /*           modifiers              */
            /*----------------------------------*/

            /*---------clear*/
            void clear();

            /*---------insert*/
            iterator insert(iterator pos, const T& value );

            iterator insert(iterator pos, size_type count, const T& value );

            /*this insert is declare here because of "enable_if" to make shure inputIt is an itterator*/
            template< class InputIt>
            iterator insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<InputIt::input_iter, InputIt>::type = NULL)
            {
                if (!capacity())
                {
                    difference_type n = ft::distance(first, last);
                    _start = _alloc.allocate(n);
                    _end_capacity = _start + n;
                    _end = _start;
                    while (n--)
                    {
                        _alloc.construct(_end, *first);
                        first++;
                        _end++;
                    }
                }
                if (pos >= iterator(_start) && pos <= iterator(_end))
                {
                    difference_type  distance = ft::distance(pos, this->end());
                    vector<T, Allocator>    temp1(first, last);
                    vector<T, Allocator>    temp2(pos, this->end());
                    int i = 0;
                    int j = 0;
                    
                    i = 0;
                    while (i < distance)
                    {
                        this->pop_back();
                        i++;
                    }
                    i = temp1.size();
                    while (j < i)
                        this->push_back(temp1[j++]);
                    j = 0;
                    i = temp2.size();
                    while (j < i)
                        this->push_back(temp2[j++]);
                }
                return (iterator(_end));
            };

            /*---------erase*/
            iterator erase( iterator pos );
            iterator erase( iterator first, iterator last );

            /*---------push_back*/
            void push_back(const T& value);

            /*---------pop_back*/
            void pop_back(void);

            /*---------resize*/
            void resize( size_type count, T value = T() );

            /*----------swap*/
            void swap(vector& other);
    };
}

#endif