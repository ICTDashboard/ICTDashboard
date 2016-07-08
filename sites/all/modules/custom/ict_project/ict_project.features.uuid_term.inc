<?php
/**
 * @file
 * ict_project.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ict_project_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Australian Competition and Consumer Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '009a8986-4563-4566-aeca-9ce759c4afd2',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Agriculture and Water Resources',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '0282e085-cbbb-47c8-a5b6-b355af620f00',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '8ef1c7cc-02e2-482a-9200-0394b4be4d46',
    ),
  );
  $terms[] = array(
    'name' => 'Cultural affairs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '041e0416-d522-40b4-9b05-ff8c68611d87',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Australian Fisheries Management Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '052ab3a5-6354-4b4f-a6a9-750050dd890a',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '8ef1c7cc-02e2-482a-9200-0394b4be4d46',
    ),
  );
  $terms[] = array(
    'name' => 'National Competition Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '058ecb4e-ac74-43bc-9ffa-41a5c1cf9568',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Transaction Reports and Analysis Centre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '0653d076-d994-453d-94a7-bcd2cce00477',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Commonwealth Grants Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '06b5a329-7602-4e19-b329-c8e97b570621',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Australian Information Commissioner',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '06ef90e2-bd94-44c6-83f8-67f9aa8f2eec',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Federal Court of Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '08c41df0-856e-4bb6-b62c-de49cc1b14cb',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Office of National Assessments',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '092a6d99-1f02-40c6-b1f6-38fa092b76ed',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Aged Care Quality Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '09e6796a-2fc4-4dc1-93ad-7fcb97de122b',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Law Reform Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => '0a6a9172-6ce9-470a-af75-a5713d37cee5',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Royal Australian Mint',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0b38b0d3-8de5-4628-a724-a77c12beb8ba',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Family Court and Federal Circuit Court',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0bb26746-e116-4596-bccb-8ec2109614ea',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Director of Public Prosecutions',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0c13a4cc-1f43-43d9-a10c-6eeecf3bf777',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Communications and Media Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0d059c15-f123-4a1b-aec2-737668d720c9',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '577bf767-acaa-4979-9430-0e5514eb1999',
    ),
  );
  $terms[] = array(
    'name' => 'Immigration',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '10f745a5-6dd9-4e61-87c3-1f55366a6fc8',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of the Environment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '11baacfb-7ce8-4ed7-b5e6-e62bbc654d55',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Sports Anti-Doping Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '11cbeaca-ffbb-4ce4-80cf-81ac391230af',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Agriculture and Water Resources',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '11cc0c46-1b54-4aad-a527-1e93cc95c965',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Security Intelligence Organisation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '120a6256-02fd-467a-b1f5-426ded56bf21',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Financial Security Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '1215257e-0471-415d-82e7-32d1ece6264f',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Office of Financial Management',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '1261b253-843a-4fdd-bca8-e0d87fd7505e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Royal Australian Mint',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '12e7493d-ed33-4e5a-a9b0-7dd1251f4106',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Execution – The project’s planning has been approved and the project is executing activities',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '138a4c12-af0a-48c3-af74-f36ebb928d46',
    'vocabulary_machine_name' => 'project_stage',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Science',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '141d2fe0-7bce-48ba-a334-e4d98809d456',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Tertiary Education Quality and Standards Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '16a15f01-635e-4206-b7fe-d94b8bc8d81e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bf01d8f6-e9ce-4598-af2e-02283d575903',
    ),
  );
  $terms[] = array(
    'name' => 'Family Court and Federal Circuit Court',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '17ba2236-2012-40fe-8aa1-3ed8c9a501a0',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'On hold – The project has been put temporarily on hold',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '188a9d4d-9f50-4c79-951d-c9e2ecdac5f7',
    'vocabulary_machine_name' => 'project_stage',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Department of Defence',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '19447bfb-757f-4b5a-b73f-756f720389c9',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Commonwealth Ombudsman',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '1b5b728a-5b23-4119-b586-0a5569429a50',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Department of the Senate',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '1b90f9ff-3865-4a72-be2c-2950f7ec92f6',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '32ddf846-e6fe-48b1-8942-cd47356096e7',
    ),
  );
  $terms[] = array(
    'name' => 'Bureau of Meteorology',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1c001198-0b5c-446a-a702-5d616a096b97',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Immigration and Border Protection',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 107,
    'uuid' => '1f02d43f-c99f-4725-a6d6-422930d4149e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Defence',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '210fed99-20b5-44ce-8101-34bba377affd',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '24441eac-0596-49f9-a2d1-e3c0e1e27532',
    ),
  );
  $terms[] = array(
    'name' => 'Department of the Treasury',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2415b8f9-b1e1-4b7f-959a-a6b3783c2ac9',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Defence',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 99,
    'uuid' => '24441eac-0596-49f9-a2d1-e3c0e1e27532',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Office of the Australian Accounting Standards Board',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '24b582b0-4ed0-4b3d-a575-1bcaed06a1ed',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian National Audit Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '25f65e9b-fca3-4e8d-a792-b80026924b87',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Financial Security Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2722b5dd-1351-476e-b337-6457e5f115c1',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Commission for Law Enforcement Integrity',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '2754e39e-8456-4a3b-86ca-b210256f4278',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Fair Work Ombudsman',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '278c67bb-ecd4-4247-aae6-77a4a9eea58f',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Sports Anti-Doping Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2855831b-1892-4173-9d86-e98ba4701f9d',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Attorney-General\'s',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 97,
    'uuid' => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of the Prime Minister and Cabinet',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2c2f2fb2-b9c9-4f89-b54d-fe7565eb4664',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Great Barrier Reef Marine Park Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2c97d395-eba7-4005-8a3e-302fb751f285',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Employment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 101,
    'uuid' => '2d769324-8f23-4f35-9960-636f75ad0b46',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'National Vocational Education and Training Regulator (Australian Skills Quality Authority)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '2e7955d5-8371-4d94-8f40-50f99dde2b2e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bf01d8f6-e9ce-4598-af2e-02283d575903',
    ),
  );
  $terms[] = array(
    'name' => 'Professional Services Review',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2fcb00e6-3c24-4f9e-a18a-723b995ced4a',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Funding source term 1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '309d4767-fee6-4508-874b-408abec1a040',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Parliamentary Departments',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 110,
    'uuid' => '32ddf846-e6fe-48b1-8942-cd47356096e7',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Infrastructure and Regional Development',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '331f58b1-6f9f-4bd8-9e43-9b3951ff507c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec0aba78-cc1a-47b8-bfe4-cd7c217cb154',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Fisheries Management Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '35e14e80-0502-485e-9f66-9298b372e520',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Civic infrastructure',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '365ccb17-8b4c-489d-9972-62bc6127cb8c',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Office of the Official Secretary to the Governor-General',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '373d0fbd-9e84-49f6-b8ee-01286cfd9043',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Inspector-General of Intelligence and Security',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '385df5d7-c9e7-4357-ac88-6c5f352c8bf3',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Organ and Tissue Donation and Transplantation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '391c8517-9224-4b2d-b2de-419e30dcb909',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Federal Police',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3a30a3bc-2943-414c-bd97-193ff9e21f33',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Taxation Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3a6b7a58-dc1c-4aed-9683-76c633315a61',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of National Assessments',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ab49b74-8c9e-4767-947d-db5cebaa8829',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Public Service Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3d51ef87-b04a-4a20-8c47-2aac4a214018',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Ceased – The project has been prematurely terminated (i.e. decision to stop work)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '3fd6dde7-d9c8-4f00-987a-3dd88d83ebe1',
    'vocabulary_machine_name' => 'project_stage',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Health care',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ffb40a3-b6df-4f31-9088-583872f8337d',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Parliamentary Budget Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '45177ba4-2ffd-4818-82b6-c88e3f81ae89',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian National Preventive Health Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '46012105-fba6-481a-b5cd-e7fdcc29eb2b',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Seafarers Safety, Rehabilitation and Compensation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '475844c9-cb4d-4b46-a38c-cd34f21d3bf0',
    'vocabulary_machine_name' => 'funding_source',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'International relations',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4766eb10-163a-4f5a-b082-48fa70b1edc9',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'National Competition Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '4846026b-28d4-480e-82f8-1280e89d6d21',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Bureau of Statistics',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '4a033f5c-3502-43b4-9d89-50c8bc336a46',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Department of the Senate',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4ab60ee4-3af0-4638-bd20-7b7ca97554ff',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'National Capital Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4b5b3d6a-a36d-4491-a28f-66955b212184',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Veterans\' Affairs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4bda538c-0528-4ed1-b03e-e0ef0b07a5d9',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '57858130-6cff-4764-9031-2fa5fcbd4b64',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Immigration and Border Protection',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4bdbe9b6-48c8-481c-aef9-89b0f92fdfab',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Fair Work Ombudsman',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4ca660f0-5e72-4b80-b119-764add618651',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Asbestos Safety and Eradication Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4cd8c653-5d07-4921-92ea-845a0a160117',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Seafarers Safety, Rehabilitation and Compensation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4d731f25-52f7-4be5-b668-8f8ceb3fcdc5',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Institute of Family Studies',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4e413302-804b-474a-9984-2a27e2f2457d',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '7ab7122e-ff71-44c0-8c2f-50287afe4fab',
    ),
  );
  $terms[] = array(
    'name' => 'CrimTrac Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '506b1ee1-dc5e-451b-8770-a317f9f39e5d',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Industry, Innovation and Science',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '55a7d432-a628-4d3c-b20b-12400c899df3',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec61cfdb-5ef3-4d22-9604-cda08647f6a6',
    ),
  );
  $terms[] = array(
    'name' => 'Natural resources',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '55c1af39-518b-4da3-9a0c-ded52ad1c2c9',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Clean Energy Regulator',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5704bc67-42fe-4419-b1cd-bed2689d5016',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    ),
  );
  $terms[] = array(
    'name' => 'IP Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '576cffa1-bf0c-4a81-9a7d-27a40793d4c3',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec61cfdb-5ef3-4d22-9604-cda08647f6a6',
    ),
  );
  $terms[] = array(
    'name' => 'Communications and the Arts',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 98,
    'uuid' => '577bf767-acaa-4979-9430-0e5514eb1999',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Veterans\' Affairs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 114,
    'uuid' => '57858130-6cff-4764-9031-2fa5fcbd4b64',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Australian Trade Commission (Austrade)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5910bc06-a538-45d0-8fe3-574c8328633c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Health',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 105,
    'uuid' => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Immigration and Border Protection',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5aaef466-7a37-422d-898e-4a401f853f75',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '1f02d43f-c99f-4725-a6d6-422930d4149e',
    ),
  );
  $terms[] = array(
    'name' => 'Primary industries',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5ba8df37-f6ce-4386-8f10-7c21de3571a8',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of Social Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c2c344e-26ab-4a82-80e2-cc964907e79c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Future Fund Management Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c684ddd-467e-4c45-ab5c-e479b5218db2',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '94b67797-e9ce-454b-a79b-c027c7de3507',
    ),
  );
  $terms[] = array(
    'name' => 'Climate Change Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '5eff4e52-0113-44a9-bc71-2610a5b8f1d3',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    ),
  );
  $terms[] = array(
    'name' => 'Museum of Australian Democracy at Old Parliament House',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '5f035a6a-6eee-4fcd-8f7a-487ad3402f9a',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '577bf767-acaa-4979-9430-0e5514eb1999',
    ),
  );
  $terms[] = array(
    'name' => 'Business support and regulation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '60c6ad72-aa35-4823-bec7-72d25aab1091',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Human Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 106,
    'uuid' => '60d7e329-71f1-4aa9-abea-0a32778ede45',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Australian Institute of Criminology',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '61def263-8416-45d4-864b-313f2f3a4b78',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Institute of Criminology',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '64ce2069-ae37-456d-bf40-a46eda759014',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Official Secretary to the Governor-General',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '65a4bdcd-441b-48b8-af1b-177ba9b53146',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Tourism',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '666afce7-7c47-422b-af17-978bb07fd8ae',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of Health',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6b938004-5d3f-44f4-ac68-504ebabd72e6',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of Parliamentary Counsel',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '6c9ae75e-96f8-403c-9a90-44414fae0f2f',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Workplace Gender Equality Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '72841bcf-1dbe-408a-84a1-cd0c4bb9d555',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Foreign Affairs and Trade',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '73d242ae-a16e-4c94-9a79-1e63e38203af',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Professional Services Review',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '743b27f1-23fd-4ace-ac31-f5fceafd3835',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Workplace Gender Equality Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '74a7dddd-14df-4488-a928-6021bf7b8cac',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Director of Public Prosecutions',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '750f99a9-99c5-4c63-abc4-ca8d4c9c40e0',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Federal Police',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '75dd7db7-02c8-4468-a45f-fa7263673f04',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Education and Training',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '75f4c546-b50f-407a-a891-31e8ad7cfdce',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Education and training',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '77180b52-3e2a-4e5a-b184-c00297560a02',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of the House of Representatives',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '79fd41ce-72ba-4b91-8851-71126c7a46f1',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '32ddf846-e6fe-48b1-8942-cd47356096e7',
    ),
  );
  $terms[] = array(
    'name' => 'Social Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 112,
    'uuid' => '7ab7122e-ff71-44c0-8c2f-50287afe4fab',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Museum of Australian Democracy at Old Parliament House',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7afd3446-b35d-49c9-88e7-21891da406f6',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Safe Work Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7b7ace1e-c126-4d94-be96-ac7f179da3e6',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Organ and Tissue Donation and Transplantation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '7c7b21e4-d77e-4519-a0c4-ea942b516028',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Department of the Treasury',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '7d48ebaf-ef0b-4ac0-94ee-f6ae170dbc7b',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Prudential Regulation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7e727634-e424-4666-88fa-bfcd5b1f11ea',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Communications',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7e97599c-31bc-44d0-b923-5f22522e61fa',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of the Prime Minister and Cabinet',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '7f78def0-6f04-4df4-9ff8-6895685e9dd9',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Commonwealth Grants Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '80860adf-f0f1-4e72-b8a6-041a0767eb7d',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Health',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '8117d2c6-be33-47d1-9297-4dfd30241303',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Department of the Environment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '81bc5460-c26f-4aee-9e3f-c458d2703d81',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'National Blood Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '82e8f1d4-7348-41dc-b90c-ac6de8ca9969',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Infrastructure and Regional Development',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '838e5123-993d-478f-8dfa-eb0adc837107',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'National Health Funding Body',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '85380d90-0113-4430-b1c3-1f5112a1a2d0',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Safe Work Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '864e0d6e-8153-409a-818b-35ffe8263e36',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'National Vocational Education and Training Regulator (Australian Skills Quality Authority)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8690554a-6c0f-4588-9b78-4f9de72a8d04',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Cancer Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '86e32afe-0ed0-49c4-bb43-75277088d6ba',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Transport Safety Bureau',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8732cb4d-3f14-4b16-8e28-f6a07e55519e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec0aba78-cc1a-47b8-bfe4-cd7c217cb154',
    ),
  );
  $terms[] = array(
    'name' => 'Federal Court of Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '87c46380-9ced-45f0-97dd-f6a531aedcf2',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Treasury',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 113,
    'uuid' => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Completed – The project has delivered its outputs, and has closed',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '87cc2f05-50b4-466e-8989-34635eaaffca',
    'vocabulary_machine_name' => 'project_stage',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Australian Bureau of Statistics',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8a7d789e-d622-434f-8267-55f62c21e79c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Secret Intelligence Service',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '8b617695-c57d-4707-8247-d7b18c260d02',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '9a8e592e-42cd-48cb-b517-5177c9942242',
    ),
  );
  $terms[] = array(
    'name' => 'Inspector-General of Taxation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '8bc1cfcb-ec95-42a9-b309-48c39f7f0ede',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Australian National Preventive Health Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '8e66bb6d-49fe-425d-8d53-cdda7c751982',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Agriculture and Water Resources',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 96,
    'uuid' => '8ef1c7cc-02e2-482a-9200-0394b4be4d46',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Parliamentary Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8efc4042-66f7-40ed-a869-aede6a24a879',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Fair Work Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8f356912-3d84-4ec8-a517-135ee8e04926',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Digital Transformation Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '90b44f69-fe55-4555-9ac4-9c666e35f294',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Geoscience Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '910ea387-0c7e-4502-bf5f-f55afcca33ed',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Securities and Investments Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '939aeee9-4b86-43eb-bb9b-522b0edfd3cf',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Finance',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 103,
    'uuid' => '94b67797-e9ce-454b-a79b-c027c7de3507',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Parliamentary Budget Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '95dc6a8c-0eda-491e-bd7a-138da04cb1ac',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '32ddf846-e6fe-48b1-8942-cd47356096e7',
    ),
  );
  $terms[] = array(
    'name' => 'National Mental Health Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '9883153e-b379-4db6-a2fb-b35b4c1a39ae',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Cancer Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '98dcc7e4-2297-4f53-ac4c-a061611390bd',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Commonwealth Ombudsman',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9a0e4699-42df-454b-b193-6f1d4a477ec6',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Foreign Affairs and Trade',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 104,
    'uuid' => '9a8e592e-42cd-48cb-b517-5177c9942242',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Office of the Australian Accounting Standards Board',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9aabc90d-9a9c-4b44-a508-7cfe5fe6dce4',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Foreign Affairs and Trade',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9c7eebb4-516f-4cf4-aec4-5b35fb5b17a6',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '9a8e592e-42cd-48cb-b517-5177c9942242',
    ),
  );
  $terms[] = array(
    'name' => 'Defence',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9f6e4216-38be-4c04-a456-039ca2085128',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Department of Employment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a0efae2b-eb34-488a-be7d-21ba64bfd511',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'National Health and Medical Research Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a27463c9-fa7a-40f4-9dca-b1c4eac3563f',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Crime Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'a2797407-bdab-41e9-9512-5f2d037f2167',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Trade',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a2e9a4a3-77cb-4262-857b-08c84c4d9a86',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Australian Crime Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a390309b-827f-4542-bf08-c792baed6f8a',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Bureau of Meteorology',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'a4d707b1-ffe9-4b01-a880-3550fe0d5b2a',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Electoral Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a4da1f44-ef49-45c2-bb77-3a8e0d19b903',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '94b67797-e9ce-454b-a79b-c027c7de3507',
    ),
  );
  $terms[] = array(
    'name' => 'Asbestos Safety and Eradication Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'a5dc943e-a091-4e94-bc1a-a301d8a26a3f',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Transaction Reports and Analysis Centre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5ea6ff8-cf3b-40b6-a3a9-45d22aca34f6',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Community services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a9197dd3-053e-413c-a68b-4174b68ec4f7',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Australian Securities and Investments Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a9839d5c-6b60-4b00-b66e-4f1bd1f03b1c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Veterans\' Affairs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a9b7db5b-8103-4ec0-9710-f54224d248d4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'CrimTrac Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => 'ae69c418-a256-4d2f-ade6-d4340e820a03',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Commission for Law Enforcement Integrity',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af551384-483f-4533-8e4c-9902aeb26bcc',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian National Audit Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af648d41-df39-47c8-9661-eb21dbba7d0d',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of the House of Representatives',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af65e540-e619-418c-a882-9d65b40a4575',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Centre for International Agricultural Research',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'b01aec94-f691-4118-b754-1bfd794ab255',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '9a8e592e-42cd-48cb-b517-5177c9942242',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Transport Safety Bureau',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b0227289-3f52-45a8-8bed-9906341a032b',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Great Barrier Reef Marine Park Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'b1725ca6-6cac-4e7c-b992-ea051ee0582e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    ),
  );
  $terms[] = array(
    'name' => 'IP Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b2514b9f-facc-4f26-8863-79ac09a1f9bb',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Governance',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b3f9374b-35a7-4587-b9d5-96c9fe1987f9',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Australian Public Service Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'b48b8f9c-80f4-45d8-bc0e-e913cc41f003',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Office of Financial Management',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b4a21e1c-9139-44fd-a3f0-7ffbcaee0ec4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Environment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 102,
    'uuid' => 'b4deb192-41b9-47fe-98d5-d2ad256f1968',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Human Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b6f2f2f9-684e-48b2-b7e3-c836af3fce3c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '60d7e329-71f1-4aa9-abea-0a32778ede45',
    ),
  );
  $terms[] = array(
    'name' => 'National Archives of Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'b6f52405-c562-46b1-ba17-c7ede49f8308',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Transport',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b9f723c7-b467-40ce-82f7-4c29cd187ce0',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Justice administration',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc2eef23-bd89-465f-a247-29cb99e1b380',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Administrative Appeals Tribunal',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'bca5d71a-dba9-417b-9282-c5a2f75f1f5e',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Prime Minister and Cabinet',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 111,
    'uuid' => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Social Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'be30918f-028e-4b73-b5ad-166ab3e91ddb',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '7ab7122e-ff71-44c0-8c2f-50287afe4fab',
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Fair Work Building Industry Inspectorate',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'bea53e1e-c76e-43c7-a268-d1935cec58fd',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Education and Training',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 100,
    'uuid' => 'bf01d8f6-e9ce-4598-af2e-02283d575903',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Department of Industry, Innovation and Science',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bf77b22a-38f6-4c47-8739-d316b95166c1',
    'vocabulary_machine_name' => 'funding_source',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Environment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c0750fa0-39bc-4f96-9195-1a8b95ddd8c4',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Productivity Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'c29fad2f-5698-47e6-a0b0-0125a1e0ea5b',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Aged Care Quality Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c30def94-5f82-4f16-9685-14ac76fbf95c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Taxation Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'c4ab70ae-fdbe-4ccb-89a2-4e7d90264a42',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Law Reform Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cadc0056-3a05-441b-8cca-e17df8971496',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Secret Intelligence Service',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cb8e582a-0da5-42ff-8112-1364a09f3f64',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Start up – Detailed planning and setup for the project is underway',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbe76c93-a5d1-41ed-9408-d75995b37fb1',
    'vocabulary_machine_name' => 'project_stage',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Fair Work Building Industry Inspectorate',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cf07123d-8836-4c3f-b5ab-be4c8b757510',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Climate Change Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd091944c-4dad-4999-a905-37b37f668482',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Sport and recreation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd18e654c-dd84-4ab1-8f32-eaeee348ac17',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Security',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd1ac5cbb-43e3-41c2-8a46-211a67eae14b',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'National Health and Medical Research Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'd2c175d1-592f-4d1e-952e-c8b7eb0ec267',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Research Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd4035cde-e069-40fe-b293-c02ddb60feaf',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bf01d8f6-e9ce-4598-af2e-02283d575903',
    ),
  );
  $terms[] = array(
    'name' => 'Fair Work Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'd5d180ad-26be-476d-9202-556eb9b2143c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2d769324-8f23-4f35-9960-636f75ad0b46',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Finance',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd699bbf4-9675-46d6-89dd-e696e2373a5c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '94b67797-e9ce-454b-a79b-c027c7de3507',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Prudential Regulation Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'd70efab3-eb58-4e55-8b27-789d4c20a0f7',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Human Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd8ad9289-e348-4db4-9609-c755cf2f8363',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Trade Commission (Austrade)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'da385a58-a574-4d10-b958-e6a9f5e27339',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '9a8e592e-42cd-48cb-b517-5177c9942242',
    ),
  );
  $terms[] = array(
    'name' => 'Digital Transformation Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'dbec3781-04b6-45ee-a970-ec3e3807fdeb',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bd3e6765-f576-432f-b444-eb0bd95d30ff',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Institute of Family Studies',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dc57662d-cf4f-42b3-854d-9bf8a410d85f',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Auditing and Assurance Standards Board',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dc7435ea-0019-4f52-99e2-f17d50d0ed6e',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Inspector-General of Intelligence and Security',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dc8b6b7b-0ae0-494a-b785-37382d96f187',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Indigenous affairs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dd7880f3-d379-4e7c-8102-8856d42e3c82',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Productivity Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dfa1ac86-6381-42b5-9578-e7f5f9b049e4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Funding source term 2',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e1f00bca-bb30-496f-ade7-452340e7f365',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Employment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e217c0ad-3b31-4e14-a6e3-d7b6e71c5fe5',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Australian Competition and Consumer Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e242cf58-d19f-4269-bd30-f93737dff3ab',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'National Archives of Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e32976e6-c7b0-447e-bc56-7509111ffaa9',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Communications and the Arts',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e4f773fe-8966-43a3-9b72-43520346c2b1',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Parliamentary Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e58616b0-6320-4e9d-936d-6e5e3cfe279c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '32ddf846-e6fe-48b1-8942-cd47356096e7',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Finance',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e609a9fb-6c0e-4ec2-a8e8-f063cb57a089',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Security Intelligence Organisation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => 'e8274753-45d7-475c-9de1-c2f251715163',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Department of Education and Training',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e894e3b3-8cb0-4dec-8658-815527751eeb',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'bf01d8f6-e9ce-4598-af2e-02283d575903',
    ),
  );
  $terms[] = array(
    'name' => 'Future Fund Management Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ea386fff-6a16-4e71-b8b8-03b8c7ec4e33',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Infrastructure and Regional Development',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 109,
    'uuid' => 'ec0aba78-cc1a-47b8-bfe4-cd7c217cb154',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'Industry, Innovation and Science',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 108,
    'uuid' => 'ec61cfdb-5ef3-4d22-9604-cda08647f6a6',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
  );
  $terms[] = array(
    'name' => 'National Health Funding Body',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'f13594fa-4a83-4a5c-85bd-9294c09e647c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'National Mental Health Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f1cb68cc-6371-4e66-8523-dc950352d1ca',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Tertiary Education Quality and Standards Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f271f466-2f4c-4c38-a945-36dd4574a0f8',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Radiation Protection and Nuclear Safety Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f2801583-21fb-4cd8-b6d0-667f50cd20af',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '593535ea-5290-40e7-823d-2fb3bc0cdcf3',
    ),
  );
  $terms[] = array(
    'name' => 'Australian Electoral Commission',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f3365972-5c04-4c9a-9318-bff85340627c',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Finance management',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f391c628-fbc1-4d1e-8596-0a84c3186edd',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'Geoscience Australia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'f39426d8-7e2b-4b88-a68d-06e0d574808c',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec61cfdb-5ef3-4d22-9604-cda08647f6a6',
    ),
  );
  $terms[] = array(
    'name' => 'Office of Parliamentary Counsel',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f4a391e0-d319-477d-a228-b4affad94d84',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Employment',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f502b1e1-ea76-410f-b620-3bfb75c29bf4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Research Council',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f56f9d19-ec43-4e79-8bf7-95589b2382fd',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Australian Information Commissioner',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f632eae7-6e8d-424c-b080-b30330d2a90e',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Office of the Auditing and Assurance Standards Board',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'f69aa6e3-9a20-441a-842c-00e6c5dbf3e4',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '87cb2d49-47d9-4380-882f-71bc8a03da62',
    ),
  );
  $terms[] = array(
    'name' => 'Maritime services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f70dfcbf-52e7-4d19-b226-f9c26657842d',
    'vocabulary_machine_name' => 'project_category',
  );
  $terms[] = array(
    'name' => 'National Blood Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f7d16751-08cd-4fc0-9134-166824ebb61d',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Inspector-General of Taxation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f807d2ae-8568-477f-9f82-cec91ab7beaa',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Clean Energy Regulator',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f828670c-e917-4101-ad46-2bb87067a5e9',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Administrative Appeals Tribunal',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f8948c6d-573c-45c5-bd79-fce750373ae4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Department of Communications and the Arts',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'f9953884-da21-4f37-a78b-a261df3d45f9',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '577bf767-acaa-4979-9430-0e5514eb1999',
    ),
  );
  $terms[] = array(
    'name' => 'Attorney-General\'s Department',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'fa2e98be-c20b-4499-ba6f-ce04407ba0c0',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => '2adbb306-a109-499c-b79d-fe6d9bd1851b',
    ),
  );
  $terms[] = array(
    'name' => 'Attorney-General\'s Department',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'faf3b5fe-fed2-4d25-9c5e-9d4b4505e79f',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Communications and Media Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fc28c204-1539-4579-9684-617d2158c0e4',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Radiation Protection and Nuclear Safety Agency',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fca868f0-7095-41b5-b45f-803f7828a183',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Australian Centre for International Agricultural Research',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fdf3975d-7936-4d70-8ff0-f1028ac9e716',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'National Capital Authority',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'fe89b7ae-36a4-43f3-8361-0b14f84f5bdc',
    'vocabulary_machine_name' => 'portfolio',
    'field_abbreviation' => array(),
    'parent' => array(
      0 => 'ec0aba78-cc1a-47b8-bfe4-cd7c217cb154',
    ),
  );
  return $terms;
}
