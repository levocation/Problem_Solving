class Solution {
    public int solution(int total, int w, int n) {
        int answer = 0;
        
        int h = (total / w) + (total % w > 0 ? 1 : 0);
        
        int[][] container = new int[h][w];
        boolean isStraightDir = true;
        
        int target_h = 0, target_w = 0;
        
        int num = 1;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (isStraightDir) {
                    container[i][j] = num;
                } else {
                    container[i][w - j - 1] = num;
                }
                
                if (num == n) {
                    target_h = i;
                    target_w = (isStraightDir ? j : (w - j - 1));
                }
                num++;
                if (num > total) break;
            }
            if (num > total) break;
            isStraightDir = !isStraightDir;
        }
        
        while (target_h < h) {
            if (container[target_h][target_w] == 0) break;
            answer++;
            target_h++;
        }
        
        return answer;
    }
}