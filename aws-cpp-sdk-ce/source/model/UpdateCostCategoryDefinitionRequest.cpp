﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ce/model/UpdateCostCategoryDefinitionRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::CostExplorer::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateCostCategoryDefinitionRequest::UpdateCostCategoryDefinitionRequest() : 
    m_costCategoryArnHasBeenSet(false),
    m_ruleVersion(CostCategoryRuleVersion::NOT_SET),
    m_ruleVersionHasBeenSet(false),
    m_rulesHasBeenSet(false)
{
}

Aws::String UpdateCostCategoryDefinitionRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_costCategoryArnHasBeenSet)
  {
   payload.WithString("CostCategoryArn", m_costCategoryArn);

  }

  if(m_ruleVersionHasBeenSet)
  {
   payload.WithString("RuleVersion", CostCategoryRuleVersionMapper::GetNameForCostCategoryRuleVersion(m_ruleVersion));
  }

  if(m_rulesHasBeenSet)
  {
   Array<JsonValue> rulesJsonList(m_rules.size());
   for(unsigned rulesIndex = 0; rulesIndex < rulesJsonList.GetLength(); ++rulesIndex)
   {
     rulesJsonList[rulesIndex].AsObject(m_rules[rulesIndex].Jsonize());
   }
   payload.WithArray("Rules", std::move(rulesJsonList));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateCostCategoryDefinitionRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSInsightsIndexService.UpdateCostCategoryDefinition"));
  return headers;

}




