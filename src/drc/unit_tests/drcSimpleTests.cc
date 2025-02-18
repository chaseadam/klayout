
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2021 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#include "tlUnitTest.h"
#include "dbReader.h"
#include "dbTestSupport.h"
#include "dbNetlist.h"
#include "dbNetlistSpiceReader.h"
#include "lymMacro.h"
#include "tlFileUtils.h"

TEST(1)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_1.drc";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au1.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = nil\n"
        "$drc_test_target = '%s'\n"
      , output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(2)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_2.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drctest.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au2.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(3_Flat)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_3.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drctest.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au3.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(4_Hierarchical)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_4.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drctest.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au4.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(5_FlatAntenna)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_5.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/antenna_l1.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au5.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(6_HierarchicalAntenna)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_6.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/antenna_l1.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au6.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(7_AntennaWithDiodes)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_7.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/antenna_l1.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au7.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(8_TextsAndPolygons)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_8.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/texts.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au8.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

static void compare_netlists (tl::TestBase *_this, const std::string &cir, const std::string &cir_au)
{
  db::Netlist nl, nl_au;

  db::NetlistSpiceReader reader;

  {
    tl::info << "Output: " << cir;
    tl::InputStream is (cir);
    reader.read (is, nl);
  }

  {
    tl::info << "Golden: " << cir_au;
    tl::InputStream is (cir_au);
    reader.read (is, nl_au);
  }

  db::compare_netlist (_this, nl, nl_au);
}

TEST(9_NetlistExtraction)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_9.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/ringo.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au9a.cir";

  std::string au_simplified = tl::testsrc ();
  au_simplified += "/testdata/drc/drcSimpleTests_au9b.cir";

  std::string output = this->tmp_file ("tmp.cir");
  std::string output_simplified = this->tmp_file ("tmp_simplified.cir");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_target_simplified = '%s'\n"
      , input, output, output_simplified)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);


  //  verify

  CHECKPOINT ();
  compare_netlists (_this, output, au);

  CHECKPOINT ();
  compare_netlists (_this, output_simplified, au_simplified);
}

TEST(10_NetlistExtractionFlat)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_10.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/ringo.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au10a.cir";

  std::string au_simplified = tl::testsrc ();
  au_simplified += "/testdata/drc/drcSimpleTests_au10b.cir";

  std::string output = this->tmp_file ("tmp.cir");
  std::string output_simplified = this->tmp_file ("tmp_simplified.cir");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_target_simplified = '%s'\n"
      , input, output, output_simplified)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);


  //  verify

  CHECKPOINT ();
  compare_netlists (_this, output, au);

  CHECKPOINT ();
  compare_netlists (_this, output_simplified, au_simplified);
}

TEST(11_CustomDevices)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_11.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/vdiv.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au11a.cir";

  std::string au_simplified = tl::testsrc ();
  au_simplified += "/testdata/drc/drcSimpleTests_au11b.cir";

  std::string output = this->tmp_file ("tmp.cir");
  std::string output_simplified = this->tmp_file ("tmp_simplified.cir");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_target_simplified = '%s'\n"
      , input, output, output_simplified)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);


  //  verify

  CHECKPOINT ();
  compare_netlists (_this, output, au);

  CHECKPOINT ();
  compare_netlists (_this, output_simplified, au_simplified);
}

TEST(12_NetlistJoinLabels)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_12.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/implicit_nets.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au12a.cir";

  std::string output = this->tmp_file ("tmp.cir");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_target_simplified = nil\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  //  verify

  CHECKPOINT ();
  compare_netlists (_this, output, au);
}

TEST(13a_KissingCorners)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_13a.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/kissing_corners.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au13a.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  //  verify

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  CHECKPOINT ();
  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(13b_KissingCornersDeep)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_13b.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/kissing_corners.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au13b.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  //  verify

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  CHECKPOINT ();
  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(14_SwitchingTargets)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_14.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_14.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au14.gds";

  std::string au2 = tl::testsrc ();
  au2 += "/testdata/drc/drcSimpleTests_au14_2.gds";

  std::string output = this->tmp_file ("tmp.gds");
  std::string output2 = this->tmp_file ("tmp2.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_target2 = '%s'\n"
      , input, output, output2)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);

  db::Layout layout2;

  {
    tl::InputStream stream (output2);
    db::Reader reader (stream);
    reader.read (layout2);
  }

  db::compare_layouts (_this, layout2, au2, db::NoNormalization);
}

TEST(15_issue548)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_15.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_15.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au15.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

//  Edges::extents isn't deep-enabled
TEST(16_issue570)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_16.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_16.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au16.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

//  Problems with Source#select
TEST(17_issue570)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_17.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_17.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au17.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(18_forget)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_18.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_18.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au18.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(19_shielding)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_19.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_19.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au19.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(20_interact_with_count)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_20.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_20.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au20.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(21_breaking)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_21.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_21.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au21.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(22_opposite_filter)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_22.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_22.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au22.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(23_rect_filter)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_23.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_23.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au23.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(24_enclosing)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_24.drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_24.gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au24.gds";

  std::string output = this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
      , input, output)
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

static void run_test (tl::TestBase *_this, const std::string &number, bool deep)
{
  std::string rs = tl::testsrc ();
  rs += "/testdata/drc/drcSimpleTests_" + number + ".drc";

  std::string input = tl::testsrc ();
  input += "/testdata/drc/drcSimpleTests_" + number + ".gds";

  std::string au = tl::testsrc ();
  au += "/testdata/drc/drcSimpleTests_au" + number + std::string (deep ? "d" : "") + ".gds";

  std::string output = _this->tmp_file ("tmp.gds");

  {
    //  Set some variables
    lym::Macro config;
    config.set_text (tl::sprintf (
        "$drc_test_source = '%s'\n"
        "$drc_test_target = '%s'\n"
        "$drc_test_deep = %s\n"
      , input, output, deep ? "true" : "false")
    );
    config.set_interpreter (lym::Macro::Ruby);
    EXPECT_EQ (config.run (), 0);
  }

  lym::Macro drc;
  drc.load_from (rs);
  EXPECT_EQ (drc.run (), 0);

  db::Layout layout;

  {
    tl::InputStream stream (output);
    db::Reader reader (stream);
    reader.read (layout);
  }

  db::compare_layouts (_this, layout, au, db::NoNormalization);
}

TEST(25_spaceWithOptions)
{
  run_test (_this, "25", false);
}

TEST(25d_spaceWithOptions)
{
  run_test (_this, "25", true);
}

TEST(26_attributes)
{
  run_test (_this, "26", false);
}

TEST(26d_attributes)
{
  run_test (_this, "26", true);
}

TEST(27_advancedShielding)
{
  run_test (_this, "27", false);
}

TEST(27d_advancedShielding)
{
  run_test (_this, "27", true);
}

TEST(28_inputFragmentation)
{
  run_test (_this, "28", true);
}

TEST(29_holes)
{
  run_test (_this, "29", false);
}

TEST(29d_holes)
{
  run_test (_this, "29", true);
}

TEST(30_density)
{
  run_test (_this, "30", false);
}

TEST(31_globaTransformation)
{
  run_test (_this, "31", false);
}

TEST(31d_globalTransformation)
{
  run_test (_this, "31", true);
}

TEST(32_globalTransformationWithClip)
{
  run_test (_this, "32", false);
}

TEST(32d_globalTransformationWithClip)
{
  run_test (_this, "32", true);
}

TEST(33_globalTransformationWithTiles)
{
  run_test (_this, "33", true);
}

TEST(40_fill)
{
  run_test (_this, "40", false);
}

TEST(41_fillTiled)
{
  run_test (_this, "41", false);
}

TEST(42_fillWithLeft)
{
  run_test (_this, "42", false);
}

TEST(43_fillWithLeftTiled)
{
  run_test (_this, "43", false);
}

TEST(44_fillWithOverlappingBoxes)
{
  run_test (_this, "44", false);
}

TEST(45_fillWithOverlappingBoxesTiled)
{
  run_test (_this, "45", false);
}

TEST(46_fillWithOverlappingBoxes)
{
  run_test (_this, "46", false);
}

TEST(47_fillWithOverlappingBoxesTiled)
{
  run_test (_this, "47", false);
}
