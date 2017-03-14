public class Programa {

	public static void main(String[] args) {
		
		Hilo1 h1 = new Hilo1();
		h1.start();
		
		System.out.println(h1.toString() + " | " + h1.getId());
		
		try {
			h1.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		System.out.println(h1.isAlive());
		new Hilo2().start();
		
		
		
		Hilo3 h3 = new Hilo3();
		Thread t3 = new Thread(h3);
		t3.start();
		
		
		new Thread(new Runnable() {
			
			public void run() {
				// TODO Auto-generated method stub
				System.out.println("Como va eso");
			}
		}).start();
		
		
		new Thread(new Runnable() {
			
			public void run() {
				// TODO Auto-generated method stub
				new Thread(new Runnable() {
					
					public void run() {
						// TODO Auto-generated method stub
						new Thread(new Runnable() {
							
							public void run() {
								// TODO Auto-generated method stub
								new Thread(new Runnable() {
									
									public void run() {
										// TODO Auto-generated method stub
										new Thread(new Runnable() {
											
											public void run() {
												// TODO Auto-generated method stub
												new Thread(new Runnable() {
													
													public void run() {
														// TODO Auto-generated method stub
														new Thread(new Runnable() {
															
															public void run() {
																// TODO Auto-generated method stub
																new Thread(new Runnable() {
																	
																	public void run() {
																		// TODO Auto-generated method stub
																		new Thread(new Runnable() {
																			
																			public void run() {
																				// TODO Auto-generated method stub
																				new Thread(new Runnable() {
																					
																					public void run() {
																						// TODO Auto-generated method stub
																						new Thread(new Runnable() {
																							
																							public void run() {
																								// TODO Auto-generated method stub
																								new Thread(new Runnable() {
																									
																									public void run() {
																										// TODO Auto-generated method stub
																										new Thread(new Runnable() {
																											
																											public void run() {
																												// TODO Auto-generated method stub
																												new Thread(new Runnable() {
																													
																													public void run() {
																														// TODO Auto-generated method stub
																														new Thread(new Runnable() {
																															
																															public void run() {
																																// TODO Auto-generated method stub
																																new Thread(new Runnable() {
																																	
																																	public void run() {
																																		// TODO Auto-generated method stub
																																		new Thread(new Runnable() {
																																			
																																			public void run() {
																																				// TODO Auto-generated method stub
																																				new Thread(new Runnable() {
																																					
																																					public void run() {
																																						// TODO Auto-generated method stub
																																						new Thread(new Runnable() {
																																							
																																							public void run() {
																																								// TODO Auto-generated method stub
																																								new Thread(new Runnable() {
																																									
																																									public void run() {
																																										// TODO Auto-generated method stub
																																										new Thread(new Runnable() {
																																											
																																											public void run() {
																																												// TODO Auto-generated method stub
																																												new Thread(new Runnable() {
																																													
																																													public void run() {
																																														// TODO Auto-generated method stub
																																														new Thread(new Runnable() {
																																															
																																															public void run() {
																																																// TODO Auto-generated method stub
																																																new Thread(new Runnable() {
																																																	
																																																	public void run() {
																																																		// TODO Auto-generated method stub
																																																		new Thread(new Runnable() {
																																																			
																																																			public void run() {
																																																				// TODO Auto-generated method stub
																																																				new Thread(new Runnable() {
																																																					
																																																					public void run() {
																																																						// TODO Auto-generated method stub
																																																						new Thread(new Runnable() {
																																																							
																																																							public void run() {
																																																								// TODO Auto-generated method stub
																																																								new Thread(new Runnable() {
																																																									
																																																									public void run() {
																																																										// TODO Auto-generated method stub
																																																										new Thread(new Runnable() {
																																																											
																																																											public void run() {
																																																												// TODO Auto-generated method stub
																																																												new Thread(new Runnable() {
																																																													
																																																													public void run() {
																																																														// TODO Auto-generated method stub
																																																														new Thread(new Runnable() {
																																																															
																																																															public void run() {
																																																																// TODO Auto-generated method stub
																																																																new Thread(new Runnable() {
																																																																	
																																																																	public void run() {
																																																																		// TODO Auto-generated method stub
																																																																		new Thread(new Runnable() {
																																																																			
																																																																			public void run() {
																																																																				// TODO Auto-generated method stub
																																																																				new Thread(new Runnable() {
																																																																					
																																																																					public void run() {
																																																																						// TODO Auto-generated method stub
																																																																						new Thread(new Runnable() {
																																																																							
																																																																							public void run() {
																																																																								// TODO Auto-generated method stub
																																																																								new Thread(new Runnable() {
																																																																									
																																																																									public void run() {
																																																																										// TODO Auto-generated method stub
																																																																										new Thread(new Runnable() {
																																																																											
																																																																											public void run() {
																																																																												// TODO Auto-generated method stub
																																																																												new Thread(new Runnable() {
																																																																													
																																																																													public void run() {
																																																																														// TODO Auto-generated method stub
																																																																														new Thread(new Runnable() {
																																																																															
																																																																															public void run() {
																																																																																// TODO Auto-generated method stub
																																																																																new Thread(new Runnable() {
																																																																																	
																																																																																	public void run() {
																																																																																		// TODO Auto-generated method stub
																																																																																		new Thread(new Runnable() {
																																																																																			
																																																																																			public void run() {
																																																																																				// TODO Auto-generated method stub
																																																																																				new Thread(new Runnable() {
																																																																																					
																																																																																					public void run() {
																																																																																						// TODO Auto-generated method stub
																																																																																						System.out.println("Manuel style");
																																																																																					}
																																																																																				}).start();
																																																																																			}
																																																																																		}).start();
																																																																																	}
																																																																																}).start();
																																																																															}
																																																																														}).start();
																																																																													}
																																																																												}).start();
																																																																											}
																																																																										}).start();
																																																																									}
																																																																								}).start();
																																																																							}
																																																																						}).start();
																																																																					}
																																																																				}).start();
																																																																			}
																																																																		}).start();
																																																																	}
																																																																}).start();
																																																															}
																																																														}).start();
																																																													}
																																																												}).start();
																																																											}
																																																										}).start();
																																																									}
																																																								}).start();
																																																							}
																																																						}).start();
																																																					}
																																																				}).start();
																																																			}
																																																		}).start();
																																																	}
																																																}).start();
																																															}
																																														}).start();
																																													}
																																												}).start();
																																												
																																											}
																																										}).start();
																																									}
																																								}).start();
																																							}
																																						}).start();
																																					}
																																				}).start();
																																			}
																																		}).start();
																																	}
																																}).start();
																															}
																														}).start();
																													}
																												}).start();
																											}
																										}).start();
																									}
																								}).start();
																							}
																						}).start();
																					}
																				}).start();
																			}
																		}).start();
																	}
																}).start();
															}
														}).start();
													}
												}).start();
											}
										}).start();
									}
								}).start();
							}
						}).start();
					}
				}).start();
			}
		}).start();
		
		
		System.out.println("Hola desde el principal.");

	}
	
}
