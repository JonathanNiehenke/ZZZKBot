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
  void ZZZKBotAIModule::collectEnemyBuildingsPos(
        std::set<BWAPI::Position>& lastKnownEnemyUnliftedBuildingsAnywherePosSet,
        std::function<bool (BWAPI::Unit)> isNotStolenGas);
  void ZZZKBotAIModule::collectEnemyPositions(
        BWAPI::Position firstEnemyNonWorkerSeenPos,
        BWAPI::Position closestEnemySeemPos,
        BWAPI::Position furthesEnemySeenPos, BWAPI::Position myStartPos,
        std::set<BWAPI::Position>& lastKnownEnemyUnliftedBuildingsAnywherePosSet,
        std::function<bool (BWAPI::Unit)> isNotStolenGas);
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
  void ZZZKBotAIModule::determineWorkerDefense(
        bool& workersShouldRetaliate,
        bool& shouldDefend,
        bool isBuildingLowLife,
        int workerCount,
        BWAPI::Unitset attackableEnemyNonBuildingThreatUnits,
        std::map<const BWAPI::UnitType, int> allUnitCount);
  void ZZZKBotAIModule::determineWorkerTarget(
        BWAPI::Unit workerAttackTarget,
        BWAPI::Unit u,
        BWAPI::Unit startBaseAuto,
        bool shouldDefend);
  BWAPI::Unit ZZZKBotAIModule::determineWorkerTargetBackup();
  BWAPI::TilePosition ZZZKBotAIModule::determineBuildLocation(
        BWAPI::Unit builder,
        BWAPI::UnitType buildingType,
        BWAPI::Unit startBaseAuto,
        BWAPI::Unit& geyserAuto);
  void ZZZKBotAIModule::construct(
        BWAPI::Unit builder,
        BWAPI::UnitType buildingType,
        BWAPI::TilePosition targetBuildLocation,
        BWAPI::Unit& geyserAuto,
        BWAPI::Unit& reservedBuilder);
  void ZZZKBotAIModule::prepareForConstruction(
        BWAPI::Unit builder,
        BWAPI::UnitType buildingType,
        BWAPI::TilePosition targetBuildLocation,
        BWAPI::Unit& reservedBuilder);
  void ZZZKBotAIModule::displaceMineralGatherer(
        BWAPI::Unit mineralGatherer,
        std::map<const BWAPI::Unit, BWAPI::Unit>& gathererToResourceMapAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& resourceToGathererMapAuto);
  void ZZZKBotAIModule::prepAndConstructBuilding(
        BWAPI::Unit builder,
        BWAPI::UnitType buildingType,
        BWAPI::TilePosition& targetBuildLocation,
        BWAPI::Unit& geyserAuto,
        BWAPI::Unit& reservedBuilder,
        int& frameLastCheckedBuildLocation,
        int checkBuildLocationFreqFrames,
        BWAPI::Unit startBaseAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& gathererToResourceMapAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& resourceToGathererMapAuto);
  void ZZZKBotAIModule::prepAndBuild(
        BWAPI::UnitType builderType,
        BWAPI::UnitType buildingType,
        BWAPI::Unit lowLifeDrone,
        BWAPI::TilePosition& targetBuildLocation,
        BWAPI::Unit& geyserAuto,
        BWAPI::Unit& reservedBuilder,
        int& frameLastCheckedBuildLocation,
        int checkBuildLocationFreqFrames,
        BWAPI::Unit startBaseAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& gathererToResourceMapAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& resourceToGathererMapAuto,
        BWAPI::Unit oldReservedBuilder);
  void ZZZKBotAIModule::makeUnit(
        BWAPI::Unit startBaseAuto,
        std::map<const BWAPI::UnitType, int> allUnitCount,
        std::map<const BWAPI::Unit, BWAPI::Unit> gathererToResourceMapAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit> resourceToGathererMapAuto,
        BWAPI::Unit lowLifeDrone,
        BWAPI::Unit& geyserAuto,
        const BWAPI::UnitType& buildingType,
        BWAPI::Unit& reservedBuilder,
        BWAPI::TilePosition& targetBuildLocation,
        int& frameLastCheckedBuildLocation,
        int checkBuildLocationFreqFrames,
        bool isNeeded);
  void ZZZKBotAIModule::constructBuilding(
        BWAPI::UnitType buildingType,
        std::function<void (const BWAPI::UnitType&, BWAPI::Unit&,
            BWAPI::TilePosition&, int&, const int, const bool)> makeUnitLamda,
        BWAPI::Unit& builder,
        std::map<const BWAPI::UnitType, int> allUnitCount,
        int numWorkersTrainedThisFrame,
        int supplyUsed,
        int transitionOutOfFourPool,
        BWAPI::Unit lowLifeDrone,
        bool isSpeedlingBuild);
  void ZZZKBotAIModule::recruitToGas(
        BWAPI::Unit u,
        std::map<const BWAPI::Unit, BWAPI::Unit>& gathererToResourceMapAuto,
        std::map<const BWAPI::Unit, BWAPI::Unit>& resourceToGathererMapAuto,
        int& lastAddedGathererToRefinery);
  BWAPI::Unit ZZZKBotAIModule::identifyOpportunityTarget(
        BWAPI::Unit u,
        std::function<BWAPI::Unit (const BWAPI::Unit& bestUnitYet,
                                   const BWAPI::Unit& curUnit)>
            getBestEnemyThreatUnitLambda);
  BWAPI::Unit ZZZKBotAIModule::getBestEnemyThreatUnit(
        const BWAPI::Unit& u,
        const BWAPI::Unit& bestUnitYet,
        const BWAPI::Unit& curUnit);


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
