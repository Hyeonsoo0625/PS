import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Node{
    List<Integer> parent = new ArrayList<>();
    int floor;
}
public class Main {
    static int[] parent = new int[1001];
    static int[] floor = new int[1001];
    static Node[] node = new Node[1001];
    public static void set_tree(int nod, int pnode){
        parent[nod]=pnode;
        floor[nod]=floor[pnode]+1;
        for(int i=0;i<node[nod].parent.size();i++){
            int child = node[nod].parent.get(i);
            if(child == pnode){
                continue;
            }
            set_tree(child, nod);
        }
    }
    public static int LCA(int a, int b){
        if(floor[a]<floor[b]){
            int temp = a;
            a=b;
            b=temp;
        }
        while(floor[a]!=floor[b]){
            a=parent[a];
        }
        while(a!=b){
            a=parent[a];
            b=parent[b];
        }
        return a;
    }
    public static void main(String[] args) {
        for(int i=0;i<1001;i++){
            node[i]=new Node();
        }
        node[1].floor=1;
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        for(int i=0;i<N-1;i++){
            int c = scanner.nextInt();
            node[i+2].parent.add(c);
            node[c].parent.add(i+2);
        }
        set_tree(1,0);
        for(int i=0;i<M;i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            System.out.println(LCA(a,b));
        }
    }
}