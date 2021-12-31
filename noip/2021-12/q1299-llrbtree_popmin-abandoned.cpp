struct Node * moveleft(struct Node *rt) {
    // IMPORTANT!: 删除操作的核心功能
    rt->flip();
    if (rt->rchild != nullptr)
        if (rt->rchild->lchild != nullptr)
            if (rt->rchild->lchild->colored) {
                rotrev(rt->rchild);
                rotate(rt);
                rt->flip();
            }
    return rt;
}

struct Node * popmin(struct Node **rt) {
    // ASSERT!: `rt`由紅遍連接其親代節點
    if ((*rt)->lchild != nullptr) {
        /**
         * 左孩子存在的情況：
         *  首先明確!:這個節點不是最小值
         *  TODO!:補充
         */
        struct Node * _lchnode = (*rt)->lchild;
        if (_lchnode->lchild != nullptr)
            if (!(_lchnode->colored) && !(_lchnode->lchild->colored))
                (*rt) = moveleft(*rt);
        return popmin(&_lchnode);
    } else {
        /**
         * 沒有左孩子的情況：
         *  此時即來到最小值，
         *  開始檢驗右孩子以判斷下一步的決策...
         */
        if ((*rt)->rchild != nullptr) {
            /**
             * 右孩子不爲空的情況：
             *  接管其右孩子的值、顔色、左右子樹,
             *  然後從它本人開始修正；
             */
            (*rt)->val = (*rt)->rchild->val;
            (*rt)->colored = (*rt)->rchild->colored;
            (*rt)->lchild = (*rt)->rchild->lchild;
            if ((*rt)->lchild != nullptr)
                (*rt)->lchild->parent = (*rt);
            (*rt)->rchild = (*rt)->rchild->rchild;
            if ((*rt)->rchild != nullptr)
                (*rt)->rchild->parent = (*rt);
            return fixup(*rt);
        } else {
            /**
             * 右孩子爲空的情況：
             *  此時可以判斷該節點左右孩子皆不存在，
             *  直接把該節點置空，
             *  然後回頭修正它的父節點;
             */
            struct Node * _tofix = (*rt)->parent;
            (*rt) = nullptr;
            return fixup(_tofix);
        }
    }
}
