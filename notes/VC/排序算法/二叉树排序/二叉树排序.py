# -*- coding:utf-8 -*-

import sys

reload(sys)
sys.setdefaultencoding('utf-8')


class BSTNode:
    """
    ����һ���������ڵ��ࡣ
    �������㷨Ϊ����������һЩ������������ͽ����жϵ����⡣
    """
    def __init__(self, data, left=None, right=None):
        """
        ��ʼ��
        :param data: �ڵ㴢�������
        :param left: �ڵ�������
        :param right: �ڵ�������
        """
        self.data = data
        self.left = left
        self.right = right


class BinarySortTree:
    """
    ����BSTNode��Ķ�����������ά��һ�����ڵ��ָ�롣
    """
    def __init__(self):
        self._root = None

    def is_empty(self):
        return self._root is None

    def search(self, key):
        """
        �ؼ������
        :param key: �ؼ���
        :return: ��ѯ�ڵ��None
        """
        bt = self._root
        while bt:
            entry = bt.data
            if key < entry:
                bt = bt.left
            elif key > entry:
                bt = bt.right
            else:
                return entry
        return None

    def insert(self, key):
        """
        �������
        :param key:�ؼ���
        :return: ����ֵ
        """
        if self.is_empty():
            self._root = BSTNode(key)

        bt = self._root

        while True:
            entry = bt.data

            if key < entry:
                if bt.left is None:
                    bt.left = BSTNode(key)
                bt = bt.left
            elif key > entry:
                if bt.right is None:
                    bt.right = BSTNode(key)
                bt = bt.right
            else:
                bt.data = key
                return

    def delete(self, key):
        """
        ������������ӵķ���
        :param key: �ؼ���
        :return: ����ֵ
        """
        p, q = None, self._root # ά��pΪq�ĸ��ڵ㣬���ں�������Ӳ���
        if not q:
            print("������")
            return
        while q and q.data != key:
            p = q
            if key < q.data:
                q = q.left
            else:
                q = q.right
            if not q: # ������û�йؼ���keyʱ�������˳���
                return
        # �����ѽ��ҵ���Ҫɾ���Ľڵ㣬��q���á���p����q�ĸ��ڵ����None��qΪ���ڵ�ʱ����
        if not q.left:
            if p is None:
                self._root = q.right
            elif q is p.left:
                p.left = q.right
            else:
                p.right = q.right
            return
        # ���ҽڵ�q�������������ҽڵ㣬��q������������Ϊ�ýڵ��������
        # �÷������ܻ�����������ȣ�Ч�ʲ�����ߡ�������������ķ�����
        r = q.left
        while r.right:
            r = r.right
        r.right = q.right
        if p is None:
            self._root = q.left
        elif p.left is q:
            p.left = q.left
        else:
            p.right = q.left

    def _pre_order(self, node=None):

        if node is None:
            node = self._root

        yield node.data

        if node.left is not None:
            for item in self._pre_order(node.left):
                yield item
        if node.right is not None:
            for item in self._pre_order(node.right):
                yield item

    def _mid_order(self, node=None):
        if node is None:
            node = self._root

        if node.left is not None:
            for item in self._mid_order(node.left):
                yield item

        yield node.data

        if node.right is not None:
            for item in self._mid_order(node.right):
                yield item

    def _mid_order1(self):
        """
        ʵ�ֶ���������������㷨,
        չʾ���Ǵ����Ķ���������.
        ֱ��ʹ��python���õ��б���Ϊһ��ջ��
        :return: data
        """
        stack = []
        node = self._root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            yield node.data
            node = node.right

    def _post_order(self, node=None):
        if node is None:
            node = self._root

        if node.left is not None:
            for item in self._post_order(node.left):
                yield item

        if node.right is not None:
            for item in self._post_order(node.right):
                yield item

        yield node.data

    def pre_order(self):
        return list(self._pre_order())

    def mid_order(self):
        return list(self._mid_order()) # return list(self._mid_order1())

    def post_order(self):
        return list(self._post_order())


if __name__ == '__main__':
    lis = [62, 58, 88, 47, 73, 99, 35, 51, 93, 37]
    bs_tree = BinarySortTree()
    for i in range(len(lis)):
        bs_tree.insert(lis[i])

    print "���������", bs_tree.pre_order()
    print "���������", bs_tree.mid_order()
    print "���������", bs_tree.post_order()