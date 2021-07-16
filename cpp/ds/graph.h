#define MaxVertexNum 100
#define EdgeInfo int
#define VertexInfo int

#ifndef GL
#define GL
typedef struct ArcNode {
    Edgeinfo weight;
    int tailvex, headvex; // 边关联的两个顶点
    ArcNode *tlink, *hlink; // 两个顶点的下一条边
} ArcNode;

typedef struct VNode {
    VertexInfo data;
    ArcNode *firstin, *firstout; // 顶点的第一条入边和出边
} VNode;

typedef struct {
    VNode xlist[MaxVertexNum]; // 顶点向量
    int arcnum, vexnum;
} GLGraph;
//* 从顶点的firstin沿着hlink的链即顶点的所有入边 
//* 从顶点的firstout沿着tlink的链即顶点的所有出边 
#endif

#ifndef AML
#define AML
typedef struct ArcNode {
    bool mark;
    EdgeInfo weight;
    int ivex, jvex; // 边关联的两个顶点
    ArcNode *ilink, *jlink; // 两个顶点的下一条边
} ArcNode;

typedef struct VNode {
    VertexInfo data;
    ArcNode *firstEdge; // 顶点的第一条边
} VNode;

typedef struct {
    VNode adjmulist[MaxVertexNum]; // 顶点向量
    int arcnum, vexnum;
} AMLGraph;
//* 所有依附于同一顶点的边串联在同一链表中
#endif