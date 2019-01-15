/*
* Explore.h, part of VCMI engine
*
* Authors: listed in file AUTHORS in main folder
*
* License: GNU General Public License v2.0 or later
* Full text of license available in license.txt file, in main folder
*
*/
#pragma once

#include "CGoal.h"

struct HeroPtr;
class VCAI;
class FuzzyHelper;

namespace Goals
{
	class DLL_EXPORT Explore : public CGoal<Explore>
	{
	private:
		bool allowGatherArmy;

	public:
		Explore(bool allowGatherArmy)
			: CGoal(Goals::EXPLORE), allowGatherArmy(allowGatherArmy)
		{
			priority = 1;
		}

		Explore()
			: Explore(true)
		{
		}

		Explore(HeroPtr h)
			: CGoal(Goals::EXPLORE)
		{
			hero = h;
			priority = 1;
		}
		TGoalVec getAllPossibleSubgoals() override;
		TSubgoal whatToDoToAchieve() override;
		std::string completeMessage() const override;
		bool fulfillsMe(TSubgoal goal) override;
		virtual bool operator==(const Explore & other) const override;

	private:
		TSubgoal exploreNearestNeighbour(HeroPtr h) const;
		TSubgoal explorationNewPoint(HeroPtr h) const;
		TSubgoal explorationBestNeighbour(int3 hpos, int radius, HeroPtr h) const;
		TSubgoal explorationScanRange(HeroPtr h, std::vector<int3> & range) const;
		#if 0
		bool hasReachableNeighbor(const int3 &pos, HeroPtr hero, CCallback * cbp, VCAI * vcai) const;
		#endif

		void getVisibleNeighbours(
			const std::vector<int3> & tiles,
			std::vector<int3> & out,
			CCallback * cbp,
			const TeamState * ts) const;

		int howManyTilesWillBeDiscovered(
			const int3 & pos,
			int radious,
			CCallback * cbp,
			const TeamState * ts,
			VCAI * aip,
			HeroPtr h) const;
	};
}
