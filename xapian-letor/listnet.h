/* listnet.h: The ListNET file.
 *
 * Copyright (C) 2012 Rishabh Mehrotra
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef LISTNET_H
#define LISTNET_H


#include <xapian.h>
#include <xapian/base.h>
#include <xapian/types.h>
#include <xapian/visibility.h>

#include "ranker.h"
#include "ranklist.h"
//#include "evalmetric.h"

#include <list>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
namespace Xapian {

class XAPIAN_VISIBILITY_DEFAULT ListNET: public Ranker {

  public:
    string models;
    vector<double> parameters;
    double tolerance_rate;
    double learning_rate;
    vector<Xapian::RankList> training_data;
    
  public:
    ListNET() {};

    Xapian::RankList rank(const Xapian::RankList rlist);
    
    void set_training_data(vector<Xapian::RankList> training_data1);

    void learn_model();

    void load_model(const std::string & model_file_name);

    void save_model(const std::string & model_file_name);

    double score_doc(Xapian::FeatureVector fv);
    
    vector<double> listnet_train(vector<RankList> & samples);

};

}
#endif /* LISTMLE_H */
