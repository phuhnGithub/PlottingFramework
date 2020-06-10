// Plotting Framework
//
// Copyright (C) 2019-2020  Mario Krüger
// Contact: mario.kruger@cern.ch
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "MultDepSpec.h"

//****************************************************************************************
/**
 * Playground for testing.
 */
//****************************************************************************************
void MultDepSpec::DefineTrackQAPlots(PlotManager& plotManager)
{
  //string dataSet =
  string plotGroup = "tracks";

  { // -----------------------------------------------------------------------
    string plotName = "chi2PerCluster";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.6, 0.8);
    plot[1]["Y"].SetRange(0., 0.1);
    plot[1]["X"].SetMaxRange(4.);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "findableClusters";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.3, 0.7);
    //plot[1]["Y"].SetRange(0., 0.1);
    plot[1]["X"].SetMinRange(120);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "foundClusters";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    plot[1]["Y"].SetRange(0., 0.045);
    plot[1]["X"].SetMinRange(80);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "sharedClusters";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    plot[1]["Y"].SetRange(1e-7, 1.).SetLog();
    plot[1]["X"].SetMaxRange(65);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "fractionSharedClusters";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    plot[1]["Y"].SetRange(1e-7, 1.).SetLog();
    plot[1]["X"].SetMaxRange(0.43);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "crossedRows";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    plot[1]["Y"].SetRange(0., 0.34);
    plot[1]["X"].SetMinRange(140);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "crossedRowsOverFindable";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.18, 0.88);
    plot[1]["Y"].SetRange(0., 0.45);
    plot[1]["X"].SetRange(0.94, 1.08);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "nClustersPID";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.18, 0.88);
    plot[1]["Y"].SetRange(0., 0.027);
    //plot[1]["X"].SetRange(0.94, 1.08);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "goldenChi2";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.6, 0.85);
    plot[1]["Y"].SetRange(0., 0.25);
    plot[1]["X"].SetMaxRange(20);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "geomLength";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "tpc-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "tpc-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    //plot[1]["Y"].SetRange(0., 0.25);
    plot[1]["X"].SetMinRange(120);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "its-foundClusters";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.2, 0.85);
    plot[1]["Y"].SetRange(0., 0.48);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------


  { // -----------------------------------------------------------------------
    string plotName = "eta";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "track-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "track-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "track-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "track-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.18, 0.88);
    plot[1]["Y"].SetRange(0.0112, 0.013);
    plot[1]["X"].SetRange(-0.8, 0.8);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

  { // -----------------------------------------------------------------------
    string plotName = "phi";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "track-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "track-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "track-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "track-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.62, 0.28);
    plot[1]["Y"].SetRange(0.005, 0.013);
    //plot[1]["X"].SetRange(-0.8, 0.8);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------


  { // -----------------------------------------------------------------------
    string plotName = "signed1Pt";
    Plot plot(plotName, plotGroup, "1d");
    plot[1].AddData({string("PbPb_2015/Data/") + "trackpar-" + plotName, "cutStudies"},"Pb-Pb, 2015")
    .SetOptions(curve).SetLine(kRed, kSolid, 3.);
    plot[1].AddData({string("PbPb_2015/MC/") + "trackpar-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kRed, kDashed, 3.);

    plot[1].AddData({string("PbPb_2018/Data/") + "trackpar-" + plotName, "cutStudies"},"Pb-Pb, 2018")
    .SetOptions(curve).SetLine(kBlue, kSolid, 3.);
    plot[1].AddData({string("PbPb_2018/MC/") + "trackpar-" + plotName, "cutStudies"},"")
    .SetOptions(curve).SetLine(kBlue, kDashed, 3.);

    plot[1].AddLegend(0.13, 0.92);
    //plot[1]["Y"].SetRange(0.0112, 0.013);
    plot[1]["X"].SetRange(-6.2, 6.2);

    plotManager.AddPlot(plot);
  } // -----------------------------------------------------------------------

}