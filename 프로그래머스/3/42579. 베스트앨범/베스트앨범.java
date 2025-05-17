import java.util.*;
class Song implements Comparable<Song> {
    int id, plays;
    
    Song(int id, int plays) {
        this.id = id;
        this.plays = plays;
    }
    
    @Override
    public int compareTo(Song o) {
        if (this.plays == o.plays) return this.id - o.id;
        return o.plays - this.plays;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        HashMap<String, Integer> cnt = new HashMap<>();
        HashMap<String, List<Song>> song = new HashMap<>();
        
        for (int i=0;i<genres.length;i++) {
            String genre = genres[i];
            int play = plays[i];
            
            cnt.put(genre, cnt.getOrDefault(genre, 0) + play);
            song.putIfAbsent(genre, new ArrayList<>());
            song.get(genre).add(new Song(i, play));
        }
        
        List<String> sortedGenres = new ArrayList<>(cnt.keySet());
        sortedGenres.sort((a,b) -> cnt.get(b) - cnt.get(a));
        
        List<Integer> answer = new ArrayList<>();
        
        for (String genre : sortedGenres) {
            List<Song> songs = song.get(genre);
            Collections.sort(songs);
            
            answer.add(songs.get(0).id);
            if (songs.size() > 1) {
                answer.add(songs.get(1).id);
            }
        }
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}