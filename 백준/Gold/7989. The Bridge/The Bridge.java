import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Long.sum;
import static java.util.Collections.min;
import static java.util.Collections.sort;

public class Main {

    public static List<Long> list = new ArrayList<Long>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        Long a;
        Long result = 0L;
        n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            a = Long.parseLong(br.readLine());
            list.add(a);
        }
        sort(list);
        if(n==1){
            result = list.get(0);
        } else if (n == 2) {
            result = list.get(1);
        }
        else {
            if (n % 2 == 1) {
                for (int i = n - 1; i > 2; i -= 2) {
                    result += Math.min(list.get(1) * 2 + list.get(0) + list.get(i), list.get(i - 1) + list.get(i) + list.get(0) * 2);
                }
                result += list.get(0) + list.get(1) + list.get(2);
            } else {
                for (int i = n - 1; i > 1; i -= 2) {
                    result += Math.min(list.get(1) * 2 + list.get(0) + list.get(i), list.get(i - 1) + list.get(i) + list.get(0) * 2);
                }
                result += list.get(1);
            }
        }
        System.out.println(result);
    }
}