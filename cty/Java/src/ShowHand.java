import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class SowHand {
    private final int play_NUM = 5;
    private  String[] types = {"方块","草花","红心","黑桃"};
    private  String[] values = {"2", "3","4","5","6","7","8","9","10","J","Q","K","A"};
    private List<String> cards = new LinkedList<String>();
    private String[] players = new String[PLAY_NUM];
    public void initCards()
    {
        for(int i = 0 ; i < types.length ; i++)
        {
            for(int j =0;j<values.length;j++)
            {
                cards.add(types[i] + values[j]);
            }
        }
        Collections.shuffle(cards);
    }
}
public void initPlayer(String... names)
{
    if(names.length > PLAY_NUM || names.length < 2)
    {
        System.out.println("玩量不对");
        return ;
    }
    else
    {
        for(int i = 0; i < names.length ; i++ )
        {
            players[i] =names[i];
        }
    }
}
public void initPlayerCards()
{
    for(int i =0; i< Players.length ; i++)
    {
        if(players[i] !=null && !players[i].equals(""))
        {
            playersCards[i] = new LinkedList<String>();
        }
    }
}