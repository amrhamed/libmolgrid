/*
 * example_providers.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: dkoes
 */

#include <exampleref_providers.h>

namespace libmolgrid {

template<>
void ReceptorStratifiedExampleRefProvider<BalancedExampleRefProvider, 2>::setup() {
  //balanced requires acive and decoys, so filter out receptors that don't have both for convenience
  vector<BalancedExampleRefProvider> tmp;
  currenti = 0; currentk = 0;

  for(unsigned i = 0, n = examples.size(); i < n; i++)
  {
    if(examples[i].num_actives() > 0 && examples[i].num_decoys() > 0) {
      //eliminate empty buckets
      tmp.push_back(examples[i]);
      tmp.back().setup();
    }
    else if(examples[i].num_actives() > 0)
    {
      ExampleRef tmp;
      examples[i].next_active(tmp);
      LOG(INFO) << "Dropping receptor " << tmp.files[0] << " with no decoys.";
    }
    else if(examples[i].num_decoys() > 0)
    {
      ExampleRef tmp;
      examples[i].next_decoy(tmp);
      LOG(INFO) << "Dropping receptor " << tmp.files[0] << " with no actives.";
    }
  }

  swap(examples,tmp);
  if(randomize) shuffle(examples.begin(), examples.end(), random_engine);

}

} /* namespace libmolgrid */
