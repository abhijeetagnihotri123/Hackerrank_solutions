

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def top_view(root, m, hd,level):
    if not root:
        return 
    if hd in m:
        if level < m[hd][1]:
            m.update( {hd : [root.info,level] })
    else:
        m[hd] = [root.info,level]

    top_view(root.left, m, hd-1,level+1)
    top_view(root.right,m, hd+1, level+1)

def topView(root):
    m={}
    top_view(root, m, 0,0)
    mn = 100000
    mx = -100000
    for key,value in m.items():
        if mx < key:
            mx = key
        if mn > key:
            mn = key
    i = mn
    while i <= mx:
        print (m[i][0],end = " ")
        i = i+1


