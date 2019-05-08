链路规划问题：
需求1：求一个n个节点无向连通图的最小生成树
需求2：除了需求1的静态权值外，还要考虑节点的方向数(节点与非父节点的连接数量)
      方向数  权重
		1      1
		2      2
		3      3
		……     ……
		10+    10
需求3：除了考虑需求1、2，还要考虑链路深度(节点到根节点的路径中边的数量)
      链路深度  权重
		1      1
		2      2
		3      3
		……     ……
		10+    10
需求4：除了考虑需求1、2、3，还要考虑节点的子孙数
      子孙数   权重
	   [0,5]    2
	   [6,10]   4		
	   [11,15]  6		
	   [16,20]  8		
	   [20,...] 10	
需求5：需求1、2、3、4只考虑单根节点，如给定多个根节点，求出该图的最小生成森林	