class Solution {
    
    public int convert(String time) {
        return (time.charAt(0) - '0') * 600
             + (time.charAt(1) - '0') * 60
             + (time.charAt(3) - '0') * 10
             + (time.charAt(4) - '0'); 
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int position = convert(pos);
        
        if (position < 0) position = 0;
        if (position > convert(video_len)) position = convert(video_len);
        if (position >= convert(op_start) && position <= convert(op_end)) position = convert(op_end);
        
        for (String command : commands) {
            if ("next".equals(command)) {
                position += 10;
            } else {
                position -= 10;
            }
            
            if (position < 0) position = 0;
            if (position > convert(video_len)) position = convert(video_len);
            if (position >= convert(op_start) && position <= convert(op_end)) position = convert(op_end);
        }
        
        answer += (position / 600);
        position %= 600;
        answer += (position / 60);
        position %= 60;
        answer += ":";
        answer += (position / 10);
        position %= 10;
        answer += position;
        
        return answer;
    }
}