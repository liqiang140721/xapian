/* listmle.cc: The ListMLE algorithm.
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

using namespace std;


using namespace Xapian;

ListMLE::ListMLE() {
}

Xapian::RankList
rank(const Xapian::RankList & rl) {

    std::map<int,double> fvals;
    std::list<FeatureVector> fvlist = rl->rl;
    std::list<FeatureVector>::const_iterator iterator;
    
    for (iterator = fvlist.begin(); iterator != fvlists.end(); ++iterator) {
	//std::cout << *iterator;
	fvals = iterator->fvals;
	
    }
}

static char* readline(FILE *input) {
    int len;

    if (fgets(line, max_line_len, input) == NULL)
	return NULL;

    while (strrchr(line, '\n') == NULL) {
	max_line_len *= 2;
	line = (char *)realloc(line, max_line_len);
	len = (int)strlen(line);
	if (fgets(line + len, max_line_len - len, input) == NULL)
	    break;
    }
    return line;
}

void
learn_model() {
    printf("Learning the model..");
    string input_file_name;
    string model_file_name;
    const char *error_msg;

    input_file_name = get_cwd().append("/train.txt");
    model_file_name = get_cwd().append("/model.txt");
    
    /* Read the training file into the format as required by the listmle_train() function
     * with datastructure vector<vector<map<int,double>>>
     */
    read_problem(input_file_name.c_str());
    ListMLE::params = listmle_train();
    ListMLE::save_model();  
}

vector<double>
listmle_train() {
    
}

    void load_model(const std::string & model_file);

    void save_model();

    double score(const Xapian::FeatureVector & fv);




