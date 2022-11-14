/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:48:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/14 13:19:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
#include "Node.hpp"
#include "swap.hpp"
#define RED_COLOR   "\033[31m"
#define RESET       "\033[0m"

namespace ft
{
    template <class T, class Allocator = std::allocator<Node<T> >, class Compare = std::less<T> >
    class RBTree
    {
        private:
            Node<T>     *root;
            Allocator   _alloc;
            Compare     _comp;
            

        public:
            void rotateLeft(Node<T> *);
            void rotateRight(Node<T> *);
            void fixInsertRBTree(Node<T> *);
            void fixDeleteRBTree(Node<T> *);
        //void inorderBST(Node<T> *);
        //void preorderBST(Node<T> *);
            int getColor(Node<T> *);
            void setColor(Node<T> *, int);
            Node<T> *minValueNode(Node<T> *) const ;
            Node<T> *maxValueNode(Node<T> *) const ;
            Node<T> *minValueNode(Node<T> *);
            Node<T> *maxValueNode(Node<T> *);
            Node<T> *insertBST(Node<T> *, Node<T> *, int*);
            Node<T> *deleteBST(Node<T> *, T);
            Node<T> *getRoot(void) const;
            Node<T> *copyTree(Node<T> *root);
            Node<T> *clearRBTree(Node<T> *root);
            int     getMaxHeight(Node<T> *root);
            void    printTreeBST(Node<T> *node, int current_level, int max_level);
        //int getBlackHeight(Node<T> *);

        public:
            RBTree(const Allocator &alloc = Allocator(), const Compare &comp = Compare());
            RBTree(RBTree const &rbt);
            virtual ~RBTree(void);
            RBTree &operator=(RBTree const &rbt);
                
            void    insertValue(T);
            void    deleteValue(T);
            void    printTree(void);
            //void    testRotateR(void);
            //void    testRotateL(void);
        //void merge(RBTree);
        //void inorder(void);
        //void preorder(void);
    };
}


#endif