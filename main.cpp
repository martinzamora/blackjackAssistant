#include <string>
#include <iostream>
#include <vector>
using namespace std;
int cardToInt (string card){
  int res;
  if(card == "A" || card == "a") res=11;
  else if (card=="J" || card == "Q" || card == "K"||card=="j" || card == "q" || card == "k") res=10;
  else res = stoi(card);
  return res;
}
int sumCards (vector <string> v){
  int res=0;
  for (int i=0; i<v.size(); i++){
    res+=cardToInt(v[i]);
  }
  /*
  if(v[0] == "A" || v[0] == "a") res+=11;
  else if (v[0]=="J" || v[0] == "Q" || v[0] == "K"||v[0]=="j" || v[0] == "q" || v[0] == "k") res+=10;
  else res+=stoi(v[0]);
  if(v[1] == "A" || v[1] == "a") res+=11;
  else if (v[1]=="J" || v[1] == "Q" || v[1] == "K"||v[1]=="j" || v[1] == "q" || v[1] == "k") res+=10;
  else res+=stoi(v[1]);
  */
  return res;
}

string coach(int sum, string a, bool status){
  string res;
  string stand = "Stand";
  string hit = "Hit";
  string d;
  if(!status) d += "Hit";
  else d+="Double Down";
  int dealer = cardToInt(a);
  if(sum==21){
    res+="Congrats! Blackjack";
  }
  else if( sum >21) res+= "Sorry, hand over.";
  else if(sum <9 && sum > 4) res+=hit;
  else if(sum > 16) res+=stand;
  else if(sum > 12 && dealer < 7) res+=stand;
  else if(sum > 12 && dealer > 6) res+=hit;
  else if(sum == 12){
    if(dealer > 3 && dealer < 7) res+=stand;
    else res+=hit;
  }
  else if(sum ==11){
    if(dealer == 11) res+=hit;
    else res+=d;
  }
  else if(sum ==10){
    if(dealer > 9) res+=hit;
    else res+=d;
  }
  else if(sum ==9){
    if(dealer < 7 && dealer > 2 ) res+=d;
    else res+=hit;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  cout<<"Welcome to My Blackjack Coach App"<<endl;
  cout<< "You should input the dealer face card and your cards."<<endl;
  cout<<"You will be coached on your best option."<<endl;
  //vector <string> cardOptions = ["1","2","3","4","5","6","7","8","9","10","J","Q","K","A"];
  /*vector <string>cardOptions;
  for (int i =1; i<11; i++){ cardOptions.push_back(to_string(i));}
  cardOptions.push_back("J");
  cardOptions.push_back("Q");
  cardOptions.push_back("K");
  cardOptions.push_back("A");
  */
  //while waiting for input
  bool exit = false;
  bool newHand = true;
  bool evaluate = false;
  string dealerCard;
  int s=0;
  string output;
  string temp;
  vector <string> userCards;
  userCards.push_back("-1");
  userCards.push_back("-1");
  while(!exit){
    //grab user input
    if(newHand){
      cout<<"What is the Dealer's face card?"<<endl;
      cin>>dealerCard;
      cout<<"What is you first card?"<<endl;
      cin>>userCards[0];
      cout<<"What is you second card?"<<endl;
      cin>>userCards[1];
      newHand = false;
      evaluate = true;
    }
    if(evaluate){
      s = sumCards(userCards);
      cout<< "your total: "<<s<<endl;
      output = coach(s, dealerCard, newHand);
      cout<<output<<endl;
      if(output == "Stand" || output == "Double Down" || output == "Congrats! Blackjack" || output== "Sorry, hand over." ){
        cout << "Hand Ended"<<endl;
        userCards.resize(2);
        newHand = true;
      }
      else{
        cout<<"What was your new card?"<<endl;
        cin>>temp;
        userCards.push_back(temp);
      }
    }
  }
  return 0;
}
