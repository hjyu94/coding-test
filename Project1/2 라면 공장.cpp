#include <string>
#include <vector>
#include <set>
using namespace std;

void Dfs(int depth, int lastDepth, vector<bool>& isImportDay, vector<vector<bool>>& choices)
{
	if (depth == lastDepth)
	{
		choices.push_back(isImportDay);
		return;
	}

	isImportDay.push_back(true);
	Dfs(depth+1, lastDepth, isImportDay, choices);
	isImportDay.pop_back();

	isImportDay.push_back(false);
	Dfs(depth+1, lastDepth, isImportDay, choices);
	isImportDay.pop_back();
}

int solution_1(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	vector<bool> isImportDay; // false, false, false
	vector<vector<bool>> choices;
	Dfs(0, dates.size(), isImportDay, choices);

	set<int> answers;
	for (int i = 0; i < choices.size(); ++i)
	{
		vector<bool>& isImportDay = choices[i];
		int count = 0;
		int remain = stock;
		for (int j = 0; j < isImportDay.size(); ++j)
		{
			if (j == 0)
				remain -= dates[j];
			else
				remain -= (dates[j] - dates[j - 1]);

			if (isImportDay[j])
			{
				remain += supplies[j];
				count++;
			}
			if (remain < 0)
			{
				break;
			}
		}
		remain -= (k - dates.back());
		if (remain < 0)
			continue;
		answers.insert(count);
	}
	return *answers.begin();
}

// 獣娃段引 ばばばばばばばばばばばばば


/************************************************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 呪脊閤聖 呪 赤澗 因厭勲 掻 亜舌 笛 葵聖 閤切
int solution_2(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>> que;
	int i = 0;
	for (int day = 0; day != k; day++) {
		if (i < dates.size() && dates[i] == day) {
			que.push(supplies[i]);
			i++;
		}
		if (!stock) {
			stock += que.top();
			que.pop();
			answer++;
		}
		stock--;
	}
	return answer;
}

void main() {
	int stock = 4;
	vector<int> dates = { 4, 10, 15 };
	vector<int> supplies = { 20, 5, 10 };
	int k = 30;

	solution_2(stock, dates, supplies, k); // 2
}
/*

	虞檎 因舌拭辞澗 馬欠拭 腔亜欠研 1宕梢 紫遂杯艦陥. 据掘 腔亜欠研 因厭閤揮 因舌税 壱舌生稽 蒋生稽 k析 戚板拭醤 腔亜欠研 因厭閤聖 呪 赤奄 凶庚拭 背須 因舌拭辞 腔亜欠研 呪脊背醤 杯艦陥.

	背須 因舌拭辞澗 狽板 腔亜欠研 因厭拝 呪 赤澗 劾促人 呪勲聖 硝形爽醸壱, 虞檎 因舌拭辞澗 錘勺搾研 匝戚奄 是背 置社廃税 判呪稽 腔亜欠研 因厭閤壱 粛柔艦陥.

	薄仙 因舌拭 害焼赤澗 腔亜欠 呪勲 stock, 腔亜欠 因厭 析舛(dates)引 背雁 獣繊拭 因厭 亜管廃 腔亜欠 呪勲(supplies), 据掘 因舌生稽採斗 因厭閤聖 呪 赤澗 獣繊 k亜 爽嬢霜 凶, 腔亜欠亜 恭嬢走走 省壱 因舌聖 錘慎馬奄 是背辞 置社廃 護 腰 背須 因舌生稽採斗 腔亜欠研 因厭閤焼醤 馬澗走研 return 馬亀系 solution 敗呪研 刃失馬室推.

	dates[i]拭澗 i腰属 因厭 亜管析戚 級嬢赤生悟, supplies[i]拭澗 dates[i] 劾促拭 因厭 亜管廃 腔亜欠 呪勲戚 級嬢 赤柔艦陥.

	薦廃紫牌
	stock拭 赤澗 腔亜欠澗 神潅(0析 戚板)採斗 紫遂桔艦陥.
	stock引 k澗 2 戚雌 100,000 戚馬脊艦陥.
	dates税 唖 据社澗 1 戚雌 k 戚馬脊艦陥.
	supplies税 唖 据社澗 1 戚雌 1,000 戚馬脊艦陥.
	dates人 supplies税 掩戚澗 1 戚雌 20,000 戚馬脊艦陥.
	k析 属拭澗 腔亜欠亜 中歳備 因厭鞠奄 凶庚拭 k-1析拭 紫遂拝 呪勲猿走幻 溌左馬檎 桔艦陥.
	dates拭 級嬢赤澗 劾促澗 神硯託授 舛慶鞠嬢 赤柔艦陥.
	dates拭 級嬢赤澗 劾促拭 因厭鞠澗 腔亜欠澗 拙穣 獣拙 穿 歯混拭 因厭鞠澗 依聖 奄層生稽 杯艦陥. 森研 級嬢 9析属拭 腔亜欠亜 郊韓蟹希虞亀, 10析属拭 因厭閤生檎 10析属拭澗 因舌聖 錘慎拝 呪 赤柔艦陥.
	腔亜欠亜 郊韓蟹澗 井酔澗 爽嬢走走 省柔艦陥.
	脊窒径 森
	stock	dates	supplies	k	result
	4	[4,10,15]	[20,5,10]	30	2
	脊窒径 森 竺誤
	薄仙 腔亜欠亜 4宕 害焼 赤奄 凶庚拭 神潅引 1析 板~3析 板猿走 紫遂馬壱 蟹檎 乞窮 腔亜欠研 陥 紫遂杯艦陥. 魚虞辞 4析 板拭澗 鋼球獣 腔亜欠研 因厭閤焼醤 杯艦陥.
	4析属 因厭閤壱 蟹檎 15析 戚板 焼徴拭澗 9宕税 腔亜欠亜 害焼赤惟 鞠壱, 戚凶 10宕聖 希 因厭閤生檎 19宕戚 害焼赤惟 桔艦陥. 15析 戚板採斗 29析 戚板猿走 琶推廃 腔亜欠澗 15宕戚糠稽 希 戚雌税 因厭精 琶推 蒸柔艦陥.
	魚虞辞 恥 2噺税 腔亜欠研 因厭閤生檎 桔艦陥.

*/