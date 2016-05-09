<?php
/**
 * @file
 * Helper functions to install, update and uninstall the sample blog module.
 */

/**
 * Creates sample content for the blog, enough to require a pager.
 */
function _sample_blog_create_demo_content() {
  global $user;

  $demo_content_entities = array();

  $entity_type = 'blog_types';
  $entity = entity_create($entity_type, array('type' => 'blog_types'));
  $wrapper = entity_metadata_wrapper($entity_type, $entity);

  $content_values = array(
    'Dragée ice cream cotton candy croissant chocolate bar muffin macaroon halvah oat cake. Fruitcake danish wafer lemon drops. Croissant oat cake cookie carrot cake biscuit. Lollipop icing sweet danish candy croissant. Pudding croissant chupa chups jujubes danish jelly-o gummi bears. Dragée cotton candy cheesecake. Tiramisu caramels chocolate bar lollipop cookie. Chocolate gummies gummi bears gummi bears topping biscuit biscuit pie. Candy canes icing marzipan sweet candy canes sweet cake cake. Gummi bears cheesecake ice cream sweet muffin cake ice cream candy. Ice cream pudding pudding chocolate bar topping chocolate bar marzipan biscuit. Wafer dessert bear claw cheesecake pie tootsie roll tootsie roll halvah. Pastry danish icing pie halvah chocolate tootsie roll.',
    'Sesame snaps chupa chups cookie tiramisu icing dessert candy jelly toffee. Tart soufflé tart bear claw dessert lollipop biscuit carrot cake dessert. Icing marzipan cake sweet. Jelly-o icing croissant marshmallow dessert pastry liquorice brownie ice cream. Marshmallow cake jelly beans pudding candy toffee jelly-o cheesecake chocolate. Cotton candy cookie lemon drops gummies. Topping fruitcake pie sugar plum chocolate bar marzipan carrot cake candy canes muffin. Chocolate chupa chups chocolate cake carrot cake biscuit. Cake croissant marshmallow. Icing sesame snaps cookie pudding oat cake chocolate cake lollipop bear claw. Chocolate cake icing chocolate bar croissant. Cake biscuit marzipan topping.',
    'Candy dessert sweet oat cake fruitcake jelly beans tootsie roll. Wafer candy tiramisu danish. Chupa chups cake pudding icing tiramisu marzipan jelly beans sesame snaps. Cookie toffee candy canes cotton candy chocolate fruitcake gummies wafer gummi bears. Caramels caramels donut oat cake topping cookie chocolate cake bonbon wafer. Chocolate bar tiramisu toffee halvah bear claw marshmallow tiramisu. Cotton candy fruitcake apple pie ice cream cotton candy danish cookie. Carrot cake halvah wafer pie candy canes sugar plum bonbon toffee. Pastry gummi bears jelly beans brownie gummi bears cotton candy gummies jujubes. Chocolate jelly oat cake gummi bears donut sweet roll. Sesame snaps powder bear claw chocolate. Sweet roll ice cream macaroon dessert chocolate cake toffee.',
  );

  for ($i = 0; $i < 12; $i++) {
    $entity = entity_create($entity_type, array('type' => 'blog_types'));
    $wrapper = entity_metadata_wrapper($entity_type, $entity);

    $entity->title = 'Post ' . ($i + 1);
    $entity->uid = $user->uid;
    $entity->created = REQUEST_TIME;
    $entity->changed = REQUEST_TIME;

    $content_value = $content_values[array_rand($content_values)];
    $wrapper->field_blog_contents->value = $content_value;
    $wrapper->field_blog_contents->summary = text_summary($content_value, NULL, 100);
    $wrapper->save();
    $demo_content_entities[] = $wrapper->getIdentifier();
  }

  variable_set('sample_blog_sample_data', $demo_content_entities);
}
