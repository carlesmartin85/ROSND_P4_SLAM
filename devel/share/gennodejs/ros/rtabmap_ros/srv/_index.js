
"use strict";

let SetLabel = require('./SetLabel.js')
let GetMap2 = require('./GetMap2.js')
let CleanupLocalGrids = require('./CleanupLocalGrids.js')
let GetMap = require('./GetMap.js')
let ListLabels = require('./ListLabels.js')
let AddLink = require('./AddLink.js')
let SetGoal = require('./SetGoal.js')
let GlobalBundleAdjustment = require('./GlobalBundleAdjustment.js')
let ResetPose = require('./ResetPose.js')
let RemoveLabel = require('./RemoveLabel.js')
let GetNodeData = require('./GetNodeData.js')
let GetPlan = require('./GetPlan.js')
let PublishMap = require('./PublishMap.js')
let DetectMoreLoopClosures = require('./DetectMoreLoopClosures.js')
let GetNodesInRadius = require('./GetNodesInRadius.js')
let LoadDatabase = require('./LoadDatabase.js')

module.exports = {
  SetLabel: SetLabel,
  GetMap2: GetMap2,
  CleanupLocalGrids: CleanupLocalGrids,
  GetMap: GetMap,
  ListLabels: ListLabels,
  AddLink: AddLink,
  SetGoal: SetGoal,
  GlobalBundleAdjustment: GlobalBundleAdjustment,
  ResetPose: ResetPose,
  RemoveLabel: RemoveLabel,
  GetNodeData: GetNodeData,
  GetPlan: GetPlan,
  PublishMap: PublishMap,
  DetectMoreLoopClosures: DetectMoreLoopClosures,
  GetNodesInRadius: GetNodesInRadius,
  LoadDatabase: LoadDatabase,
};
