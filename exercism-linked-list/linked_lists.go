// My solution for: https://exercism.org/tracks/go/exercises/linked-list/edit
package linkedlist

import "errors"

// Define List and Node types here.
type Node struct {
	Value any
	prev  *Node
	next  *Node
}

type List struct {
	head *Node
	tail *Node
}

// Note: The tests expect Node type to include an exported field with name Value to pass.

func NewList(elements ...interface{}) *List {
	list := &List{}
	for _, element := range elements {
		list.Push(element)
	}
	return list
}

func (n *Node) Next() *Node {
	return n.next
}

func (n *Node) Prev() *Node {
	return n.prev
}

func (l *List) Unshift(v interface{}) {
	newNode := &Node{Value: v, next: l.head}
	if l.head != nil {
		l.head.prev = newNode
	} else {
		l.tail = newNode
	}
	l.head = newNode
}

func (l *List) Push(v interface{}) {
	newNode := &Node{Value: v, prev: l.tail}
	if l.tail != nil {
		l.tail.next = newNode
	} else {
		l.head = newNode
	}
	l.tail = newNode
}

func (l *List) Shift() (interface{}, error) {
	if l.head == nil {
		return nil, errors.New("empty list")
	}
	node := l.head
	l.head = l.head.next
	if l.head != nil {
		l.head.prev = nil
	} else {
		l.tail = nil
	}
	return node.Value, nil
}

func (l *List) Pop() (interface{}, error) {
	if l.tail == nil {
		return nil, errors.New("empty list")
	}
	node := l.tail
	l.tail = l.tail.prev
	if l.tail != nil {
		l.tail.next = nil
	} else {
		l.head = nil
	}
	return node.Value, nil
}

func (l *List) Reverse() {
	for current := l.head; current != nil; current = current.Prev() {
		current.next, current.prev = current.prev, current.next
	}
	l.head, l.tail = l.tail, l.head
}

func (l *List) First() *Node {
	return l.head
}

func (l *List) Last() *Node {
	return l.tail
}
