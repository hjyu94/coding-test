//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//	int answer = 0;
//	
//	int n = board.size(); // n*n board, n?
//	int count = 0;
//
//	vector<vector<int>> deck(n); // vector size assign
//
//	vector<int> stickers; // 내가 뽑은 스티커들
//
//	for (int i = 0; i < n; ++i) {
//		for (int j = n-1; j >= 0; --j) {
//			int sticker = board.at(j).at(i);
//			if (sticker != 0) {
//				deck.at(i).push_back(sticker);
//			}
//		}
//	}
//
//	for (int i = 0; i < moves.size(); ++i) {
//		int target = moves.at(i);
//		--target;
//
//		if (deck.at(target).size() == 0) {
//			continue;
//		}
//		int sticker = deck.at(target).back();
//		deck.at(target).pop_back();
//		stickers.push_back(sticker);
//	}
//
//	int index = 0;
//	
//	while (stickers.size() > index + 1)
//	{
//		if (stickers.at(index) == stickers.at(index + 1)) {
//			answer = answer + 2;
//			stickers.erase(stickers.begin() + index);
//			stickers.erase(stickers.begin() + index);
//			index = 0;
//		}
//		else {
//			index++;
//		}
//	}
//
//	return answer;
//}
//
////void main() {
////	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
////	vector<int> moves = { 1,5,3,5,1,2,1,4 };
////	printf("%d", solution(board, moves));
////
////}