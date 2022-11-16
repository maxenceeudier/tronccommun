/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_impl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:00:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/16 15:01:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_IMPL_HPP
#define RBTREE_IMPL_HPP
#include "RBTree.hpp"

namespace ft
{
    template <typename T, class Allocator, class Compare>
    RBTree<T, Allocator, Compare>::RBTree(const Allocator &alloc, const Compare &comp): root(NULL), _alloc(alloc), _comp(comp){}
    
    template <typename T, class Allocator, class Compare>
    RBTree<T, Allocator, Compare>::RBTree(RBTree const &rbt): _alloc(rbt._alloc){*this = rbt;}

    template <typename T, class Allocator, class Compare>
    RBTree<T, Allocator, Compare>::~RBTree(void){root = clearRBTree(root);}

    template <typename T, class Allocator, class Compare>
    Node<T>    *RBTree<T, Allocator, Compare>::clearRBTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        root->left = clearRBTree(root->left);
        root->right = clearRBTree(root->right);
        _alloc.destroy(root);
        _alloc.deallocate(root, 1);
        return (NULL);
    }

    template <typename T, class Allocator, class Compare>
    RBTree<T, Allocator, Compare> &RBTree<T, Allocator, Compare>::operator=(RBTree<T, Allocator, Compare> const &rbt)
    {
        _alloc = rbt._alloc;
        root = copyTree(rbt.getRoot());
        return (*this);
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::copyTree(Node<T> *root)
    {
        if (!root)
            return (NULL);
        Node<T>    *node = _alloc.allocate(1);
        _alloc.construct(node, *root);
        node->left = copyTree(root->left);
        node->right = copyTree(root->right);
        if (node->left)
            node->left->parent = node;
        if (node->right)
            node->right->parent = node;
        return (node);
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::getRoot(void) const {return (root);}

    template <typename T, class Allocator, class Compare>
    void    RBTree<T, Allocator, Compare>::setRoot(Node<T> * node) {root = node;}

    template <typename T, class Allocator, class Compare>
    int RBTree<T, Allocator, Compare>::getColor(Node<T> *node)
    {
        if (!node)
            return (BLACK);
        return (node->color);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::setColor(Node<T> *node, int color)
    {
        if (!node)
            return ;
        node->color = color;
    }
    
    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::minValueNode(Node<T> *node) const
    {
        if (!node)
            return (NULL);
        if (!node->left)
            return (node);
        return (minValueNode(node->left));
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::minValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->left)
            return (node);
        return (minValueNode(node->left));
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::maxValueNode(Node<T> *node) const
    {
        if (!node)
            return (NULL);
        if (!node->right)
            return (node);
        return (maxValueNode(node->right));
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::maxValueNode(Node<T> *node)
    {
        if (!node)
            return (NULL);
        if (!node->right)
            return (node);
        return (maxValueNode(node->right));
    }

    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::insertBST(Node<T> *root, Node<T> *node, int *i)
    {
        if (!root)
            return (node);
        if (_comp(root->data ,node->data))
        {
            root->right = insertBST(root->right, node, i);
            root->right->parent = root;
        }
        if (_comp(node->data, root->data))
        {
            root->left = insertBST(root->left, node, i);
            root->left->parent = root;
        }
        if (root->data == node->data)
            *i = 0;
        return (root);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::fixInsertRBTree(Node<T> *ptr)
    {
        Node<T> *parent = NULL;
        Node<T> *grandparent = NULL;
        while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) 
        {
            parent = ptr->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left) 
            {
                Node<T> *uncle = grandparent->right;
                if (getColor(uncle) == RED) 
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    ptr = grandparent;
                }
                else
                {
                    if (ptr == parent->right)
                    {
                        rotateLeft(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateRight(grandparent);
                    ft::swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            } 
            else 
            {
                Node<T> *uncle = grandparent->left;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    ptr = grandparent;
                } 
                else 
                {
                    if (ptr == parent->left) 
                    {
                        rotateRight(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateLeft(grandparent);
                    ft::swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            }
        }
        setColor(root, BLACK);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::insertValue(T data)
    {
        int i = 1;
        Node<T>    *node = _alloc.allocate(1);
        _alloc.construct(node, data);
        root = insertBST(root, node, &i);
        if (!i)
        {
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }
        else
            fixInsertRBTree(node);
    }
    
   
    template <typename T, class Allocator, class Compare>
    void  RBTree<T, Allocator, Compare>::printTreeBST(Node<T> *node, int current_level, int max_level)
    {
        int i;
        
        if (node) 
        {
            printTreeBST(node->right, current_level + 1, max_level);
            for (i = 0; i < current_level; i++)
                std::cout << "                          ";
            if (node->color == RED)
                std::cout << RED_COLOR;
            std::cout << node->data << RESET << std::endl;
            printTreeBST(node->left, current_level + 1, max_level);
        } 
        else 
        {
            if (current_level < max_level)
            {
                printTreeBST(NULL, current_level + 1, max_level);
                for (i = 0; i < current_level; i++)
                    std::cout << "                          ";
                std::cout << "..\n";
                printTreeBST(NULL, current_level + 1, max_level);
            }
        }
    }
    
    template <typename T, class Allocator, class Compare>
    void    RBTree<T, Allocator, Compare>::printTree(void)
    {
        std::cout << "print Tree:\n";
        printTreeBST(root, 0, getMaxHeight(root));
    }

    template <typename T, class Allocator, class Compare>
    int     RBTree<T, Allocator, Compare>::getMaxHeight(Node<T> *root)
    {
        int height1 = 1;
        int height2 = 1;

        if (!root)
            return (0);
        height1 += getMaxHeight(root->right);
        height2 += getMaxHeight(root->left);
        return (std::max(height1, height2));
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::rotateLeft(Node<T> *node)
    {
        if (!node->right)
            return ;
        Node<T> *right_child = node->right;
        node->right = right_child->left;

        if (node->right != NULL)
            node->right->parent = node;
        right_child->parent = node->parent;
        if (!node->parent)
            root = right_child;
        else if (node == node->parent->right)
            node->parent->right = right_child;
        else
            node->parent->left = right_child;
        right_child->left = node;
        node->parent = right_child;
    }
    
    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::rotateRight(Node<T> *node)
    {
       if (!node->left)
            return ;
        Node<T> *left_child = node->left;
        node->left = left_child->right;

        if (node->left != NULL)
            node->left->parent = node;
        left_child->parent = node->parent;
        if (!node->parent)
            root = left_child;
        else if (node == node->parent->right)
            node->parent->right = left_child;
        else
            node->parent->left = left_child;
        left_child->right = node;
        node->parent = left_child;
    }


    template <typename T, class Allocator, class Compare>
    Node<T> *RBTree<T, Allocator, Compare>::deleteBST(Node<T> *root, T data)
    {
        T   temp;

        if (!root)
            return (root);
        if (_comp(root->data , data))
            return (deleteBST(root->right, data));
        if (_comp(data, root->data))
            return (deleteBST(root->left, data));
        if (!root->right)
            return (root);
        temp = minValueNode(root->right)->data;
        root->data = temp;
        return (deleteBST(root->right, temp));
    }
    
    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::deleteValue(T data)
    {
        Node<T> *node = deleteBST(root, data);
        fixDeleteRBTree(node);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::fixDeleteRBTree(Node<T> *node)
    {
        if (node == NULL)
            return;

        if (node == root)
        {
            root = NULL;
            return;
        }

        if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
        {
            Node<T> *child = node->left != NULL ? node->left : node->right;

            if (node == node->parent->left)
            {
                node->parent->left = child;
                if (child != NULL)
                    child->parent = node->parent;
                setColor(child, BLACK);
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
            else
            {
                node->parent->right = child;
                if (child != NULL)
                    child->parent = node->parent;
                setColor(child, BLACK);
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
        }
        else
        {
            Node<T> *brother = NULL;
            Node<T> *parent = NULL;
            Node<T> *ptr = node;
            setColor(ptr, DOUBLE_BLACK);
            while (ptr != root && getColor(ptr) == DOUBLE_BLACK)
            {
                parent = ptr->parent;
                if (ptr == parent->left)
                {
                    brother = parent->right;
                    if (getColor(brother) == RED)
                    {
                        setColor(brother , BLACK);
                        setColor(parent, RED);
                        rotateLeft(parent);
                    }
                    else
                    {
                        if (getColor(brother->left) == BLACK && getColor(brother->right) == BLACK)
                        {
                            setColor(brother, RED);
                            if(getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            ptr = parent;
                        }
                        else
                        {
                            if (getColor(brother->right) == BLACK)
                            {
                                setColor(brother->left, BLACK);
                                setColor(brother, RED);
                                rotateRight(brother);
                                brother = parent->right;
                            }
                            setColor(brother, parent->color);
                            setColor(parent, BLACK);
                            setColor(brother->right, BLACK);
                            rotateLeft(parent);
                            break;
                        }
                    }
                }
                else
                {
                    brother = parent->left;
                    if (getColor(brother) == RED)
                    {
                        setColor(brother, BLACK);
                        setColor(parent, RED);
                        rotateRight(parent);
                    }
                    else
                    {
                        if (getColor(brother->left) == BLACK && getColor(brother->right) == BLACK)
                        {
                            setColor(brother, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            ptr = parent;
                        }
                        else
                        {
                            if (getColor(brother->left) == BLACK)
                            {
                                setColor(brother->right, BLACK);
                                setColor(brother, RED);
                                rotateLeft(brother );
                                brother = parent->left;
                            }
                            setColor(brother, parent->color);
                            setColor(parent, BLACK);
                            setColor(brother->left, BLACK);
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (node == node->parent->left)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            setColor(root, BLACK);
        }
    }
    
    /*
    template <typename T, class Allocator, class Compare>
    void    RBTree<T, Allocator, Compare>::testRotateR(void){rotateRight(root);}
    
    template <typename T, class Allocator, class Compare>
    void    RBTree<T, Allocator, Compare>::testRotateL(void){rotateLeft(root);}
    
    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::inorderBST(Node<T> *ptr)
    {
        if (!ptr)
            return ;
        inorderBST(ptr->left);
        std::cout << ptr->data << " " << ptr->color << std::endl;
        inorderBST(ptr->right);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::inorder()
    {
        inorderBST(root);
        std::cout << "-------" << std::endl;
    }
    
    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::preorderBST(Node<T> *ptr)
    {
        if (ptr == NULL)
            return; 
        std::cout << ptr->data << std::endl;
        preorderBST(ptr->left);
        preorderBST(ptr->right);
    }

    template <typename T, class Allocator, class Compare>
    void RBTree<T, Allocator, Compare>::preorder()
    {
        preorderBST(root);
        std::cout << "-------" << std::endl;
    }*/
}

#endif
