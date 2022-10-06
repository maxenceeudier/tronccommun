#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <string>
#include <iostream>
#include "vector_iterator.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/distance.hpp"

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
            typedef typename ft::vectorIterator<value_type>         iterator;
            typedef std::iterator_traits<const value_type>          const_iterator;
            typedef std::reverse_iterator<iterator>                 reverse_iterator;
            typedef std::reverse_iterator<const_iterator>           const_reverse_iterator;

        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _end_capacity;
            void            _double_capacity(void);
        
        public:
            /*---------basic function----------*/
            //constructor
            explicit vector(const Allocator& alloc = std::allocator<T>() );
            explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator());
            //this constructor is declare here because of "enable_if" to make shure inputIt is an itterator
            template <class InputIt>
            vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
            : _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr){insert(_end, first, last);};
            vector(const vector &cpy);
            //destructor
            ~vector(void);
            //assignement operator
            vector  &operator=(const vector &cpy);
            //assign
            void assign(size_type count, const T &value);
            //this assign is declare here because of "enable_if" to make shure inputIt is an itterator
            template<class InputIt>
            void assign(InputIt first, InputIt last, typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
            {
                this->clear();
                this->insert(_start, first, last);
            };
            //get_alocator
            allocator_type get_allocator() const;

            /*------------acces elements-----------*/
            /*//at
            reference at(size_type pos);
            const_reference at(size_type pos) const;
            //[]
            reference operator[]( size_type pos );
            const_reference operator[]( size_type pos ) const;
            //front
            reference front();
            const_reference front() const;
            //back
            reference back();
            const_reference back() const;
            //data
            T* data();
            const T* data() const;*/

            /*-------------iterators----------------*/
            //begin
            iterator begin();
            const_iterator begin() const;
            //end
            iterator end();
            const_iterator end() const;
            //rbegin
            //reverse_iterator rbegin();
            //const_reverse_iterator rbegin() const;
            //rend
            //reverse_iterator rend();
            //const_reverse_iterator rend() const;

            /*---------------capacity---------------*/
            //empty
            bool empty() const;
            //size
            size_type size() const;
            //max_size
            //size_type max_size() const;
            //reserve
            //void reserve(size_type new_cap);
            //capacity
            size_type capacity() const;
            
            /*-----------------modifiers-------------*/
            //clear
            void clear();
            //insert
            //iterator insert( const_iterator pos, const T& value );
            iterator insert( const_iterator pos, size_type count, const T& value );
            //this insert is declare here because of "enable_if" to make shure inputIt is an itterator
            template< class InputIt>
            iterator insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
            {
                if (!pos)
                {
                    difference_type n = ft::distance(first, last);
                    _start = _alloc.allocate(n);
                    _end_capacity = _start + n;
                    _end = _start;
                    while (n--)
                    {
                        _alloc.constuct(_end, *first++);
                        _end++;
                    }
                }
                else if (pos >= _start && pos <= _end_capacity)
                {
                    vector<T, Allocator>    temp(pos, _end);
                    int i = 0;
                    while (i < _end - pos)
                    {
                        pop_back();
                        i++;
                    }
                    while (first != last)
                        push_back(*first++);
                    while (i--)
                        push_back(*temp++);
                }
                return (iterator(this->_end));
            };
            //erase
            //iterator erase( iterator pos );
            //iterator erase( iterator first, iterator last );
            //push_back
            void push_back(const T& value);
            //pop_back
            void pop_back(void);
            //resize
            //void resize( size_type count, T value = T() );
            //swap
            //void swap( vector& other );
    };

    template< class T, class Alloc >
    bool operator==(const std::vector<T,Alloc>& lhs, \
    const std::vector<T,Alloc>& rhs)
    {
        typename ft::vector<T, Alloc>::iterator itL = lhs.begin();
        typename ft::vector<T, Alloc>::iterator itR = rhs.begin(); 
        while (itL != lhs.end())
        {
            if (itR == rhs.end() || *itL != *itR)
                return (false);
            itL++;
            itR++;
        }
        return (true);
    };

    template< class T, class Alloc>
    std::ostream	&operator<<(std::ostream &o, vector<T, Alloc> &vec)
    {
        if (vec.empty())
        {
            std::string empt = "[empty]\n";
            return (o << empt);
        }
            
        typename ft::vector<T, Alloc>::iterator  it = vec.begin();

        std::string crochet = "[ ";
        o << crochet;
        while (it != vec.end() - 1)
        {
            o << *it << ", ";
            it++;
        }
        o << *it << " ]\n";
        return (o);
    }

    /*template< class T, class Alloc >
    bool operator!=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );
    
    template< class T, class Alloc >
    bool operator<( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator<=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>=( const std::vector<T,Alloc>& lhs,
                const std::vector<T,Alloc>& rhs );
    
    template< class T, class Alloc >
    void swap( std::vector<T,Alloc>& lhs,
           std::vector<T,Alloc>& rhs );*/
}

#endif