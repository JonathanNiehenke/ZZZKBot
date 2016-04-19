// Copyright 2015 Chris Coxe.
// 
// ZZZKBot is distributed under the terms of the GNU Lesser General
// Public License (LGPL) version 3.
//
// This file is part of ZZZKBot.
// 
// ZZZKBot is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// ZZZKBot is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with ZZZKBot.  If not, see <http://www.gnu.org/licenses/>.
// 
// This file was created by copying then modifying file
// ExampleAIModule/Source/ExampleAIModule.h
// of BWAPI version 4.1.2
// (https://github.com/bwapi/bwapi/releases/tag/v4.1.2 which is
// distributed under the terms of the GNU Lesser General Public License
// (LGPL) version 3).

#pragma once
#include <BWAPI.h>

// Reminder: don't use "Broodwar" in any global class constructor!

class ZZZKBotAIModule : public BWAPI::AIModule
{
private:
  void ZZZKBotAIModule::collectEnemyStartPositions(
        std::set<BWAPI::Position>& enemyStartPositions,
        std::set<BWAPI::Position>& possibleScoutPositions);
  void ZZZKBotAIModule::collectOtherStartPositions(
        BWAPI::Position& myStartPos,
        std::set<BWAPI::Position>& startPostions,
        std::set<BWAPI::Position>& otherStartPostions,
        std::set<BWAPI::Position>& enemyStartPositons,
        std::set<BWAPI::Position>& unscoutedOtherStartPositions,
        std::set<BWAPI::Position>& possibleOverlordScoutPositions);
  void ZZZKBotAIModule::enemyBuild(bool& isSpeedlingBuild, bool& isEnemyXimp);
  void ZZZKBotAIModule::countInside(
        BWAPI::Unit u, std::map<const BWAPI::UnitType, int>& allUnitCount,
        std::map<const BWAPI::UnitType, int>& incompleteUnitCount,
        int& supplyUsed);
  void ZZZKBotAIModule::countUnits(
        std::map<const BWAPI::UnitType, int>& allUnitCount,
        std::map<const BWAPI::UnitType, int>& completedUnitCount,
        std::map<const BWAPI::UnitType, int>& incompleteUnitCount,
        std::map<const BWAPI::Position, int>& numUnitsTargetingPos,
        BWAPI::Unitset myCompletedWorkers,
        int& supplyUsed,
        BWAPI::Unit& lowLifeDrone,
        bool& isBuildingLowLife,
        int scoutingTargetPosXInd,
        int scoutingTargetPosYInd);
  void ZZZKBotAIModule::collectEnemyBuildingsPos(
        std::set<BWAPI::Position>& lastKnownEnemyUnliftedBuildingsAnywherePosSet,
        std::function<bool (BWAPI::Unit)> isNotStolenGas);

public:
  // Virtual functions for callbacks, leave these as they are.
  virtual void onStart();
  virtual void onEnd(bool isWinner);
  virtual void onFrame();
  virtual void onSendText(std::string text);
  virtual void onReceiveText(BWAPI::Player player, std::string text);
  virtual void onPlayerLeft(BWAPI::Player player);
  virtual void onNukeDetect(BWAPI::Position target);
  virtual void onUnitDiscover(BWAPI::Unit unit);
  virtual void onUnitEvade(BWAPI::Unit unit);
  virtual void onUnitShow(BWAPI::Unit unit);
  virtual void onUnitHide(BWAPI::Unit unit);
  virtual void onUnitCreate(BWAPI::Unit unit);
  virtual void onUnitDestroy(BWAPI::Unit unit);
  virtual void onUnitMorph(BWAPI::Unit unit);
  virtual void onUnitRenegade(BWAPI::Unit unit);
  virtual void onSaveGame(std::string gameName);
  virtual void onUnitComplete(BWAPI::Unit unit);
  // Everything below this line is safe to modify.

};
