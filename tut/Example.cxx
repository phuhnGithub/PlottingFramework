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

#include "PlotManager.h"

int main(int argc, char *argv[])
{
  //============================================================================
  //============================================================================
  // The following examples are ment only to illustrate the use of the framework.
  // They will not compile as they are.
  // In this directory you can also find a CMakeList.txt file that can be used
  // as a starting point to create your own app linked against the PlottingFramework
  //============================================================================
  //============================================================================


  //============================================================================
  // Example 1:
  // Create a simple plot from multiple input root files.
  //============================================================================
  {
    // create plotting environment that handles IO plot creation
    PlotManager plotManager;

    // first tell the manager where to look for the data you want to use in your plots
    // the first argument gives these input files a unique identifier you can then use when creating the plots
    plotManager.AddInputDataFiles("inputGroupA", {"path/to/file/a.root", "path/to/file/a2.root"});
    plotManager.AddInputDataFiles("inputGroupB", {"path/to/file/b.root", "path/to/file/b2.root", "path/to/file/b3.root:my/sub/list/or/dir/path"});

    // N.B.:
    // you can save these settings to a file via:
    plotManager.DumpInputDataFiles("path/to/inputFilesConfig.XML");
    // this way you can also modify this list of input files manually in the
    // xml file and then read it into your program via
    plotManager.LoadInputDataFiles("path/to/inputFilesConfig.XML");


    // now that we know where to look for the data, we can start creating plot(s).
    // the plot will be handed over to the manager after it was created and defined
    // therefore it makes sense to put this part in a scope {}
    // this way you you can re-use the symbol 'plot' for the next plots

    { // -----------------------------------------------------------------------
      // create the Plot object
      Plot plot("myPlot1", "myPlotGroup"); // plots are classified in user defined groups
      // optionally you can also define figure categories within the figureGroup
      plot.SetFigureCategory("QA");
       // you always have to specify height and width of the plot:
      plot.SetDimensions(710, 710);
      plot.SetTransparent(); // for all other settings see inc/Plot.h

      // a plot consists of multiple pads, which you can access via the [] operator (counting starts at '1'):
      plot[1].SetPosition(0., 0., 1., 1.); // specifies a pad that expands over the whole plot
      plot[1].SetFillFrame(kRed+2);
      // ... see definition of Pad class in inc/Plot.h for the list of all accessors

      // you can also define default settings for ALL pads of the plot by using the padID=0, e.g.:
      plot[0].SetMargins(0.07, 0.14, 0.12, 0.07);
      plot[0].SetDefaultMarkerSize(1.2).SetDefaultLineWidth(2.);

      // now set text properties, that will be used everywhere in the pad if not overridden for a specific lable/title/etc..
      plot[1].SetDefaultTextFont(43);
      plot[1].SetDefaultTextSize(24);

      // finally we can start adding data to the plot
      plot[1].AddData({"histName1", "inputGroupA"} ,"myLable");
      // this will search for a hist/graph/fuc called histName1 in all files specified in "inputGroupA"
      // the algorithm by default recursively traverses the whole directory or list substructure of the files and returns the first match
      // in case of multiple data with the same name, living in different subfolders/lists within the file you can do
      plot[1].AddData({"folder1/histName2", "inputGroupA"} ,"myLable2");
      plot[1].AddData({"folder2/histName2", "inputGroupA"} ,"myLable3");

      // now lets add another piece of input data from the second group (this time without adding a lable to the legend)
      plot[1].AddData({"histName3", "inputGroupB"});

      // you can also simply add ratios of two input data
      plot[1].AddRatio({"histName3", "inputGroupB"}, {"histName1", "inputGroupA"}, "ratioLable");


      // to mdify how the data is displayed we can apply the settings via:
      plot[1].AddData({"histName4", "inputGroupB"}).SetOptions("HIST C").SetLine(kGreen+2, kSolid, 3.);
      // instead of directly using the ROOT drawing option string ("HIST C") you can
      // use pre-defined human readible options like curve, points, points_line, etc (you can find all available options in PlottingFramework.h):
      plot[1].AddData({"graphName1", "inputGroupA"}).SetOptions(points).SetMarker(kRed, kFullCircle, 1.);
      // all root layout settings can be applied in this manner (see definition of Data class in inc/Plot.h for the list of all accessors)

      // now add a legend containing the lables that were specified when adding the data
      plot[1].AddLegend(0.5, 0.8);
      // if you leave out the xy pad coordinates, the framework will try to auto-place the legend without overlapping your data or the axes
      plot[1].AddLegend();


      // to modify the axis titles, offsets, ranges, etc of a pad, just do the following
      plot[1]["Y"].SetTitle("my y axis tilte with meaning");
      plot[1]["X"].SetRange(1.4, 2.8).SetTitle("what i am showing on x axis").SetLog();
      plot[1]["X"].SetMaxRangeX(5.);
      // a full list of axis property accessors can be found in the Axis class definition in inc/Plot.h


      // finally after plot definition is done we can add it to the manager
      // at this point the plot object we were modifying is moved to the manager
      // and the plot object remaining in the current scope will be empty
      plotManager.AddPlot(plot);
    } // -----------------------------------------------------------------------

    // we could now add plenty of more plots to the manager....
    { // -----------------------------------------------------------------------
      //Plot plot("myPlot2", "myPlotGroup:myCategory");
      // ...
      // ...
      // plotManager.AddPlot(plot);
    } // -----------------------------------------------------------------------

    // it is also possible to construct a plot based on a copy of another
    { // -----------------------------------------------------------------------
      Plot plot("myPlot", "myPlotGroup2");
      // ...
      plot[1].AddData({"folder1/histName2", "inputGroupA"} ,"myLable2");
      //...

      // now I want to have exact same plot, but with some additional data points
      // this can be helpful to avoid useless code duplication
      Plot plot2(plot, "myPlotGroup2");
      plot2[1].AddData({"graphName1", "inputGroupB"} ,"more data");

      // now add both to the manager
      plotManager.AddPlot(plot);
      plotManager.AddPlot(plot2);
    } // -----------------------------------------------------------------------


    // to save the plots to disk as pdf you first have to tell the manager where to put them
    plotManager.SetOutputDirectory("path/to/my/OutputFolder");
    // the manager will automatically create subfolders for the figureGroups and categories
    // to generate all stored plots as pdf you can call
    plotManager.CreatePlots();

    // for a specific figureGroup, figureCategory and or plotName just specify them:
    plotManager.CreatePlots("myPlotGroup", "myCategory");
    // or
    plotManager.CreatePlots("myPlotGroup", "", {"myPlot1", "myPlot2"});
    // in case you want the pdf files to contain the figureGroup and category in the file name, you can use
    plotManager.SetUseUniquePlotNames();

    // in "interactive" mode a root canvas window will pop up
    // and you can scroll throught the plots by double clicking on the right resp. left side of the plot
    plotManager.CreatePlots("", "", {}, "interactive");

    // you can also save the plots as a root macro (.C):
    plotManager.CreatePlots("myPlotGroup", "", {"myPlot1", "myPlot2"}, "macro");

    // after you specifying a file name you can also save the plots to a .root file
    plotManager.SetOutputFileName("ResultPlots.root");
    plotManager.CreatePlots("myPlotGroup", "", {"myPlot1", "myPlot2"}, "file");
  }

  //============================================================================
  // Example 2:
  // Create plots based on a template and save plot definitions to file.
  //============================================================================
  {
    PlotManager plotManager;

    // assuming you saved the list of input root files from example 1 to a xml file via
    // plotManager.DumpInputDataFiles("path/to/inputFilesConfig.XML");
    // we can now load this directly into the manager via:
    plotManager.LoadInputDataFiles("path/to/inputFilesConfig.XML");

    // as you know from your personal plotting experience
    // there are plenty of settings that have to be applied to generate a beautyful plot
    // most of these settings e.g. the number and alignment of pads, background colors, transparency, etc..
    // stay the same for all (or a group of) your plots and you do not want to
    // verbously specify them again and again for every one of your plots
    // therefore the framework provides the optin to specify plot templates
    // these are just normal plots, but you can use their settings as a baseline for your actual plots

    // for instance the following will give you some nice default plots:
    { // -----------------------------------------------------------------------
      // template 1d
      Plot templatePlot("1d", "TEMPLATES");
      templatePlot.SetDimensions(710, 710, true);
      templatePlot.SetTransparent();
      templatePlot[0].SetDefaultTextFont(43);
      templatePlot[0].SetDefaultTextSize(24);
      templatePlot[0].SetDefaultMarkerSize(1.2);
      templatePlot[0].SetDefaultLineWidth(2.);
      templatePlot[0].SetTransparent();
      templatePlot[0].SetMargins(0.07, 0.14, 0.12, 0.07);
      templatePlot[0]["X"].SetTitleOffset(1.).SetTitleFont(43).SetTitleSize(34).SetOppositeTicks();
      templatePlot[0]["Y"].SetTitleOffset(1.2).SetTitleFont(43).SetTitleSize(34).SetOppositeTicks();
      templatePlot[1].SetPosition(0., 0., 1., 1.);
      plotManager.AddPlotTemplate(templatePlot);
    } // -----------------------------------------------------------------------

    { // -----------------------------------------------------------------------
      // template 1d ratio
      Plot templatePlot("1d_ratio", "TEMPLATES");
      templatePlot.SetDimensions(710, 710, true);
      templatePlot.SetTransparent();
      templatePlot[0].SetDefaultTextFont(43);
      templatePlot[0].SetDefaultTextSize(24);
      templatePlot[0].SetTransparent();
      templatePlot[0]["X"].SetTitleOffset(1.1);
      templatePlot[0]["Y"].SetTitleOffset(1.4);
      templatePlot[1].SetPosition(0., 0.28, 1., 1.);
      templatePlot[1].SetMargins(0.05, 0.0, 0.14, 0.05);
      templatePlot[1]["X"].SetTitleOffset(3.1);
      templatePlot[1]["Y"].SetTitleOffset(1.5);
      templatePlot[2].SetPosition(0., 0., 1., 0.28);
      templatePlot[2].SetMargins(0.015, 0.4, 0.14, 0.05);
      templatePlot[2].SetRefFunc("1");
      templatePlot[2]["X"].SetTickLength(0.06).SetTitleOffset(4.1).SetOppositeTicks();
      templatePlot[2]["Y"].SetNumDivisions(305).SetTitleOffset(1.5).SetTitleCenter();
      plotManager.AddPlotTemplate(templatePlot);
    } // -----------------------------------------------------------------------

    { // -----------------------------------------------------------------------
      // template 2d
      Plot templatePlot("2d", "TEMPLATES");
      templatePlot.SetDimensions(710, 710, true);
      templatePlot.SetTransparent();
      templatePlot[0].SetDefaultTextFont(43);
      templatePlot[0].SetDefaultTextSize(24);
      templatePlot[0].SetTransparent();
      templatePlot[0].SetMargins(0.12-0.05, 0.12+0.02, 0.12, 0.12+0.06);
      templatePlot[0]["X"].SetTitleOffset(1.1);
      templatePlot[0]["Y"].SetTitleOffset(1.1);
      templatePlot[0]["Z"].SetTitleOffset(1.6);
      templatePlot[0].SetRedrawAxes();
      templatePlot[1].SetPosition(0., 0., 1., 1.);
      plotManager.AddPlotTemplate(templatePlot);
    } // -----------------------------------------------------------------------


    // as you have seen, these template plots need to live in the figureGroup called "TEMPLATES"
    // and then be added to the manager via
    // plotManager.AddPlotTemplate(templatePlot);

    // once this is done, you can define plots based on these templates
    // by specifying their name as the third argument in the new plots' constructor:
    { // -----------------------------------------------------------------------
      Plot plot("test1d_ratio", "myFigureGroup", "1d_ratio");

      plot[1].AddData({"graph2", "inputGroupA"}, "5 TeV #Delta = #sqrt{s}")
      .SetMarker(kRed, kFullCircle, 1.2).SetMaxRangeX(40);

      plot[1].AddData({"func3", "inputGroupB"}, "ratio")
      .SetMarker(kBlack, kFullCircle, 1.2).SetMaxRangeX(70);

      plot[2].AddRatio({"invMassSpec", "inputGroupA"}, {"momentUnfolded1", "pp_5TeV"}, "ratio")
      .SetMarker(kRed, kFullCircle, 1.2)
      .SetMaxRangeX(60);

      plot[1].AddLegend(0.,0.9);
      plot[2].AddLegend(0.,0.9);

      plot[0]["X"].SetRange(20, 70).SetTickOrientation("+-");

      plotManager.AddPlot(plot);
    } // -----------------------------------------------------------------------

    // as you can see the plot definition becomes way simpler now since we
    // do not have to specify again all of the layout overhead and can focus on the content

    // instead of creating the plots directly as we have done in the previous example,
    // we can also save the plot definitions into another xml file via:
    plotManager.DumpPlots("path/to/my/plotDefinitions.XML");

    // this file can then be read in by another one of your programs via
    plotManager.ExtractPlotsFromFile("path/to/my/plotDefinitions.XML");
    // this extracts all plots from this file!
    // in case you want to load only certain figure groups:
    plotManager.ExtractPlotsFromFile("path/to/my/plotDefinitions.XML", {"figureGroup1", "figures", "figureGroup:myCategory"});
    // ... or plots:
    plotManager.ExtractPlotsFromFile("path/to/my/plotDefinitions.XML", {}, {"invMass", "ptSpec"});
    // the figure group and plot strings can be regular expressions
    // this means you can put "plot.*" and this will add "plot1", "plot123", "plot_adsf", etc.

    // instead of the default option "load", which adds these plots to the manager, the mode can also be
    // "find" in order to check only if the specified plots exist (prints out this info)
    plotManager.ExtractPlotsFromFile("path/to/my/plotDefinitions.XML", {}, {}, "find");


    // the main reasoning behind the "dump-to-file" feature is that you can then
    // make use the builtin commandline plotting tool, which can conveniently
    // create specific plots you defined and saved to file

    // to use this app you must:
    // - source the .plotrc in the main directory of the repository
    // - place both the "inputFilesConfig.XML" and "plotDefinitions.XML" (names have to be like this for now)
    //   produced by your program in some central config folder
    // - define the environment variable __PLOTTING_CONFIG_DIR to point to this folder
    // - define the environment variable __PLOTTING_OUTPUT_DIR to the directory where you want to store the created plots (pdf,png,etc.)

    // now you can run the command
    // plot
    // from everywhere
    // to see the program options run
    // plot --help
    // for zsh shells auto-completion is supported to tab through the available commands, figureGroups and plots

    // the app also has a 'browse' feature that gives you access to quickly plot the content of root files
  }

  return 0;
}